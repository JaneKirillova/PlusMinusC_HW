#ifndef HW03_HAFFMANARCHIVER_H_INCLUDED
#define HW03_HAFFMANARCHIVER_H_INCLUDED

#include "Huffman.h"
#include <iostream>
#include <fstream>

class HuffmanArchiver {
private:
	HuffmanTree treeForCompress;
	HuffmanTree treeForExtract;
	int sizeOfTheTable = 0;
	int compressedDataSize = 0;
	int unpackedDataSize = 0;

public:
	HuffmanTree getTreeForCompress();
	HuffmanTree getTreeForExtract();
	void countFrequencies(std::istream& in);
	void writeTable(std::ostream& out);
	void readTable(std::istream& in);
	void writeBit(std::ostream& out, bool bit, bool bitIsLast);
	void writeOneSymbCode(std::ostream& out, const std::vector<bool>& cod);
	void compress(std::istream& in, std::ostream& out);
	void extract(std::istream& in, std::ostream& out);
	void setFreqForTests(char ch, int fr);
	void setAmountsOfSymbolsForTests(int amount);
	void printStatistic();
};

#endif