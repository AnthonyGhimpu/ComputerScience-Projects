#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "BSTNode.hpp"
using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

class BST {
public:
	BST();
	~BST();

	fstream openFile();
	void run(BSTNode* pTree);
	void letterOpen(BSTNode* pTree);
	string search(BSTNode* pTree, char letter) const;
	void printString(string morse)const;
	void destroyTree(BSTNode* pTree);


private:
	void insert(BSTNode* pTree, BSTNode* Node);
	void inOrderPrint(BSTNode* pTree);
	BSTNode* mpRoot;

	fstream infile;
};

	