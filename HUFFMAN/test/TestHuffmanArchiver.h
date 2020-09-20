#ifndef HW03_TESTHAFFMAN_H_INCLUDED
#define HW03_TESTHAFFMAN_H_INCLUDED
#include "doctest.h"

class TestHuffmanArchiver {
public:
	HuffmanTree testReadTable();
	HuffmanTree testWriteTable();
	HuffmanTree testCountFrequencies();
	bool testBitWriting();
	bool testWriteOneSymbCode();
	bool testCompressExtractDiffSymb();
	bool testCompressExtractOneSymb();
};

#endif