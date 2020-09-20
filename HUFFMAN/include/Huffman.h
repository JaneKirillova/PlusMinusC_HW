#ifndef HW03_HAFFMAN_H_INCLUDED
#define HW03_HAFFMAN_H_INCLUDED

#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <climits>

constexpr int maxNumberOfSymbols = 1 << CHAR_BIT;

class HuffmanNode {
	char symb_;
	int freq_;
	HuffmanNode* left;
	HuffmanNode* right;

public:
	char getSymb();
	void delNode();
	bool isLeaf();
	bool canMoveDown(bool edgeValue);
	HuffmanNode* getLeft();
	HuffmanNode* getRight();
	int getFreq() const;
	HuffmanNode* moveDown(bool edgeValue);
	HuffmanNode(char symbol, int frequency);
	HuffmanNode(HuffmanNode* l, HuffmanNode* r);
};


class HuffmanTree {
private:
	HuffmanNode* root;
	int amountOfSymbols = 0;

public:
	HuffmanNode* getRoot();
	int getAmountOfSymbols();
	void setAmountOfSymbols(int amount);
	void makeTree();
	void getCode(HuffmanNode* v, std::vector<bool>& code);
	HuffmanTree();
	void DeleteTree();
	std::unordered_map<char, std::vector<bool>> codes;
	std::map<char, int> freq;
};

#endif