#include "doctest.h"
#include "HuffmanArchiver.h"
#include "Huffman.h"
#include "TestHuffmanArchiver.h"
#include <sstream>

HuffmanTree TestHuffmanArchiver::testReadTable() {
	std::stringstream str;
	int size = 3;
	str.write((char*)&size, sizeof(int));
	char ch = 'a';
	int freq = 1;
	str.write(&ch, sizeof(char));
	str.write(reinterpret_cast<char*>(&freq), sizeof(int));
	ch = 'b';
	freq = 2;
	str.write(&ch, sizeof(char));
	str.write(reinterpret_cast<char*>(&freq), sizeof(int));
	ch = 'c';
	freq = 3;
	str.write(&ch, sizeof(char));
	str.write(reinterpret_cast<char*>(&freq), sizeof(int));
	HuffmanArchiver ha;
	ha.readTable(str);
	return ha.getTreeForExtract();
};

HuffmanTree TestHuffmanArchiver::testWriteTable() {
	std::stringstream str;
	HuffmanArchiver ha;
	ha.setFreqForTests('a', 1);
	ha.setFreqForTests('b', 2);
	ha.setFreqForTests('c', 4);
	ha.setAmountsOfSymbolsForTests(3);
	ha.writeTable(str);
	ha.readTable(str);
	return ha.getTreeForExtract();
}

HuffmanTree TestHuffmanArchiver::testCountFrequencies() {
	std::stringstream str;
	HuffmanArchiver ha;
	str << "aaaaaaaaaaaaaaabbbbbbbb";
	ha.countFrequencies(str);
	return ha.getTreeForCompress();
}

bool TestHuffmanArchiver::testBitWriting() {
	std::stringstream str;
	HuffmanArchiver ha;
	ha.writeBit(str, 1, 0);
	ha.writeBit(str, 1, 0);
	ha.writeBit(str, 0, 0);
	ha.writeBit(str, 0, 0);
	ha.writeBit(str, 1, 0);
	ha.writeBit(str, 0, 1);
	char byte;
	str.read(&byte, sizeof(char));
	bool check;
	check = (byte & (1 << 0)) 
			&& (byte & (1 << 1)) 
			&& !(byte & (1 << 2)) 
			&& !(byte & (1 << 3)) 
			&& (byte & (1 << 4));
	return check;
}

bool TestHuffmanArchiver::testWriteOneSymbCode() {
	std::stringstream str;
	HuffmanArchiver ha;
	std::vector<bool> v{1, 1, 1, 1};
	ha.writeOneSymbCode(str, v);
	ha.writeBit(str, 0, 1);
	char byte;
	str.read(&byte, sizeof(char));
	bool check1;
	check1 = (byte & (1 << 0))
			&& (byte & (1 << 1))
			&& (byte & (1 << 2))
			&& (byte & (1 << 3))
			&& !(byte & (1 << 4))
			&& !(byte & (1 << 5))
			&& !(byte & (1 << 6))
			&& !(byte & (1 << 7));
	return check1;
}


bool TestHuffmanArchiver::testCompressExtractDiffSymb() {
	std::stringstream in;
	std::stringstream out;
	std::stringstream res;
	HuffmanArchiver ha;
	in << "abc-=!@#$%^&*()\nа  б  в  г";
	ha.compress(in, out);
	ha.extract(out, res);
	return in.str() == res.str();
}

bool TestHuffmanArchiver::testCompressExtractOneSymb() {
	std::stringstream in;
	std::stringstream out;
	std::stringstream res;
	HuffmanArchiver ha;
	in << "аааааааааа";
	ha.compress(in, out);
	ha.extract(out, res);
	return in.str() == res.str();
}

TestHuffmanArchiver t3;

TEST_CASE("testing working with frequencies") {
	CHECK(t3.testReadTable().freq['a'] == 1);
	CHECK(t3.testReadTable().freq['b'] == 2);
	CHECK(t3.testReadTable().freq['c'] == 3);
	CHECK(t3.testWriteTable().freq['a'] == 1);
	CHECK(t3.testWriteTable().freq['b'] == 2);
	CHECK(t3.testWriteTable().freq['c'] == 4);
	CHECK(t3.testCountFrequencies().freq['a'] == 15);
	CHECK(t3.testCountFrequencies().freq['b'] == 8);
}

TEST_CASE("testing reading and writing codes") {
	CHECK(t3.testBitWriting());
	CHECK(t3.testCompressExtractDiffSymb());
	CHECK(t3.testCompressExtractOneSymb());
	CHECK(t3.testWriteOneSymbCode());
}