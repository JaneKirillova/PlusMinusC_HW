#include "Huffman.h"
#include <queue>

HuffmanNode::HuffmanNode(char symbol, int frequency)
	: symb_(symbol)
	, freq_(frequency)
	, left(nullptr)
	, right(nullptr)
	{}


HuffmanNode::HuffmanNode(HuffmanNode* l, HuffmanNode* r)
	: left(l)
	, right(r)
	{
		freq_ = left->freq_ + right->freq_;
}

void HuffmanNode::delNode() {
	if (this == nullptr)
		return;
	left->delNode();
	right->delNode();
	delete this;
}

HuffmanNode* HuffmanNode::getLeft() {
	return left;
}

HuffmanNode* HuffmanNode::getRight() {
	return right;
}

int HuffmanNode::getFreq() const {
	return freq_;
}

char HuffmanNode::getSymb() {
	return symb_;
}

bool HuffmanNode::isLeaf() {
	return (left == nullptr && right == nullptr);
}

bool HuffmanNode::canMoveDown(bool edgeValue) {
	if (edgeValue)
		return right != nullptr;
	else
		return left != nullptr;
}

HuffmanNode* HuffmanNode::moveDown(bool edgeValue) {
	if (edgeValue)
		return right;
	else
		return left;
}

HuffmanTree::HuffmanTree() : root(nullptr) {
	for (int i = 0; i < maxNumberOfSymbols; i++)
		freq[i] = 0;
}

int HuffmanTree::getAmountOfSymbols() {
	return amountOfSymbols;
}

void HuffmanTree::setAmountOfSymbols(int amount) {
	amountOfSymbols = amount;
}

void HuffmanTree::DeleteTree() {
	root->delNode();
}

HuffmanNode* HuffmanTree::getRoot() {
	return root;
}

void HuffmanTree::getCode(HuffmanNode* root, std::vector<bool>& code) {
	if (root == nullptr)
		return;
	if (!root->getLeft() && !root->getRight())
		codes[root->getSymb()] = code;
	code.push_back(0);
	getCode(root->getLeft(), code);
	code.pop_back();
	code.push_back(1);
	getCode(root->getRight(), code);
	code.pop_back();
}

void HuffmanTree::makeTree() {
	auto comp = [](const HuffmanNode* L, HuffmanNode* R) {
		return L->getFreq() < R->getFreq();
	};

	std::multiset <HuffmanNode*, decltype(comp)> nodesSet(comp);

	for (int i = 0; i < maxNumberOfSymbols; i++) {
		if (!freq[i])
			continue;
		amountOfSymbols++;
		nodesSet.insert(new HuffmanNode(i, freq[i]));
	}
	while(nodesSet.size() != 1) {
		HuffmanNode* l = *nodesSet.begin();
		nodesSet.erase(nodesSet.begin());
		HuffmanNode* r = *nodesSet.begin();
		nodesSet.erase(nodesSet.begin());
		nodesSet.insert(new HuffmanNode(l, r));
	}
	root = *nodesSet.begin();
}
