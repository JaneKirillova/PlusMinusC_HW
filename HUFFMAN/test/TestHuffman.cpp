#include "doctest.h"
#include "HuffmanArchiver.h"
#include "Huffman.h"
#include "TestHuffman.h"
#include <sstream>

HuffmanNode TestHuffmanNode::test1() {
	HuffmanNode left('a', 10);
	HuffmanNode right('b', 11);
	HuffmanNode n(&left, &right);
	return n;
}

TestHuffmanNode t;

TEST_CASE("testing class HuffmanNode") {
	CHECK(t.test1().getFreq() == 21);
	CHECK(t.test1().getLeft()->getFreq() == 10);
	CHECK(t.test1().getRight()->getFreq() == 11);
	CHECK(t.test1().getLeft()->getSymb() == 'a');
	CHECK(t.test1().moveDown(1)->getSymb() == 'b');
	CHECK(t.test1().getRight()->isLeaf());
	CHECK(!t.test1().isLeaf());
}


HuffmanTree TestHuffmanTree::testMakeTree() {
	HuffmanTree t;
	t.freq['a'] = 1;
	t.freq['b'] = 2;
	t.freq['c'] = 3;
	t.makeTree();
	return t;
}

HuffmanTree TestHuffmanTree::testGetCode() {
	HuffmanTree t;
	t.freq['a'] = 2;
	t.freq['b'] = 4;
	t.freq['c'] = 8;
	t.freq['d'] = 16;
	t.makeTree();
	std::vector<bool> vec;
	t.getCode(t.getRoot(), vec);
	return t;
}

TestHuffmanTree t2;

TEST_CASE("testing class HuffmanTree") {
	CHECK(t2.testMakeTree().getRoot()->getFreq() == 6);
	CHECK(t2.testMakeTree().getRoot()->getLeft()->getSymb() == 'c');
	CHECK(t2.testMakeTree().getRoot()->getRight()->getLeft()->getSymb() == 'a');
	CHECK(t2.testMakeTree().getRoot()->getRight()->getRight()->getSymb() == 'b');
	CHECK(t2.testGetCode().codes['a'] == std::vector<bool>{0, 0, 0});
	CHECK(t2.testGetCode().codes['b'] == std::vector<bool>{0, 0, 1});
	CHECK(t2.testGetCode().codes['c'] == std::vector<bool>{0, 1});
	CHECK(t2.testGetCode().codes['d'] == std::vector<bool>{1});
}