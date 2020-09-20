#ifndef HW03_TESTHAFFMAN_H_INCLUDED
#define HW03_TESTHAFFMAN_H_INCLUDED
#include "doctest.h"
#include "HuffmanArchiver.h"
#include "Huffman.h"
#include <iostream>

class TestHuffmanNode {
public:
	HuffmanNode test1();
};


class TestHuffmanTree {
public:
	HuffmanTree testMakeTree();
	HuffmanTree testGetCode();
};

#endif