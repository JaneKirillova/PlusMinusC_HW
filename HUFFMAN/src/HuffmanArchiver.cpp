#include <HuffmanArchiver.h>
#include <climits>

HuffmanTree HuffmanArchiver::getTreeForCompress() {
	return treeForCompress;
}

HuffmanTree HuffmanArchiver::getTreeForExtract() {
	return treeForExtract;
}

void HuffmanArchiver::countFrequencies(std::istream & in) {
	in.seekg(0, in.end);
	int length = in.tellg();
	in.seekg(0, in.beg);
	in.clear();
	char ch;
	for (int i = 0; i < length; i++) {
		in.read(&ch, sizeof(ch));
		treeForCompress.freq[ch]++;
	}
}

void HuffmanArchiver::writeTable(std::ostream& out) {
	int size = treeForCompress.getAmountOfSymbols();
	out.write(reinterpret_cast<char*>(&size), sizeof(int));
	for (auto& symb: treeForCompress.freq) {
		if (symb.second == 0)
			continue;
		out.write(&symb.first, sizeof(char));
		out.write(reinterpret_cast<char*>(&symb.second), sizeof(int));
	}
	sizeOfTheTable = sizeof(int) + size * (sizeof(char) + sizeof(int));
}

void HuffmanArchiver::readTable(std::istream& in) {
	int size;
	in.read(reinterpret_cast<char*>(&size), sizeof(int));
	for (int i = 0; i < size; i++) {
		char symb;
		int fr;
		in.read(&symb, sizeof(symb));
		in.read(reinterpret_cast<char*>(&fr), sizeof(fr));
		treeForExtract.freq[symb] = fr;
	}
	sizeOfTheTable = sizeof(size) + size * (sizeof(char) + sizeof(int));
}

void HuffmanArchiver::writeBit(std::ostream& out, bool bit, bool bitIsLast) {
	static int pos = 0;
	static char buf = 0;

	if (!bitIsLast) {
		buf |= bit << pos;
		pos = (pos + 1) & (CHAR_BIT - 1);
		if (!pos) {
			out.write(&buf, 1);
			compressedDataSize++;
			buf = 0;
		}
	} else {
		if (pos) {
			out.write(&buf, 1);
			compressedDataSize++;
			pos = 0;
			buf = 0;
		}
		return;
	}
}

void HuffmanArchiver::writeOneSymbCode(std::ostream& out, const std::vector<bool>& cod) {
	for (int i = 0; i < cod.size(); i++)
		writeBit(out, cod[i], false);
}

void HuffmanArchiver::compress(std::istream& in, std::ostream& out) {
	in.seekg(0, in.end);
	int fileSize = unpackedDataSize = in.tellg();
	if (fileSize == 0) {
		printStatistic();
		return;
	}
	in.clear();
	in.seekg(0, in.beg);
	countFrequencies(in);
	treeForCompress.makeTree();
	std::vector<bool> vec;
	treeForCompress.getCode(treeForCompress.getRoot(), vec);
	in.clear();
	in.seekg(0, in.beg);
	writeTable(out);
	out.write(reinterpret_cast<char*>(&fileSize), sizeof(int));
	sizeOfTheTable += sizeof(int);
	for (int i = 0; i < fileSize; i++) {
		char ch;
		in.read(&ch, sizeof(ch));
		writeOneSymbCode(out, treeForCompress.codes[ch]); 
	}
	writeBit(out, 0, true);
	treeForCompress.DeleteTree();
	printStatistic();
}

void HuffmanArchiver::extract(std::istream& in, std::ostream& out) {
	in.seekg(0, in.end);
	compressedDataSize = in.tellg();
	if (compressedDataSize == 0) {
		printStatistic();
		return;
	}
	in.clear();
	in.seekg(0, in.beg);
	readTable(in);
	treeForExtract.makeTree();
	std::vector<bool> vec;
	treeForExtract.getCode(treeForExtract.getRoot(), vec);
	int sizeOfFile;
	in.read(reinterpret_cast<char*>(&sizeOfFile), sizeof(int));
	unpackedDataSize = sizeOfFile;
	sizeOfTheTable += sizeof(int);
	compressedDataSize -= sizeOfTheTable;
	HuffmanNode* node = treeForExtract.getRoot();
	char byte;
	if (node->isLeaf()) {
		for (int i = 0; i < sizeOfFile; i++) {
			out.put(node->getSymb());
		}
		printStatistic();
		return;
	}
	while(sizeOfFile) {
		in.read(&byte, 1);
		for (int i = 0; i < CHAR_BIT && sizeOfFile; i++) {
			bool bit = (byte & (1 << i));
			if (!node->canMoveDown(bit))
				node = treeForExtract.getRoot();
			node = node->moveDown(bit);
			if (node->isLeaf()) {
				out.put(node->getSymb());
				sizeOfFile--;
			}
		}
	}
	treeForExtract.DeleteTree();
	printStatistic();
}

void HuffmanArchiver::printStatistic() {
	std::cout << unpackedDataSize << "\n";
	std::cout << compressedDataSize << "\n";
	std::cout << sizeOfTheTable << "\n";
}

void HuffmanArchiver::setFreqForTests(char ch, int fr) {
	treeForCompress.freq[ch] = fr;
}

void HuffmanArchiver::setAmountsOfSymbolsForTests(int amount) {
	treeForCompress.setAmountOfSymbols(amount);
}