#pragma once

#include <iostream>
#include <fstream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

class BSTNode{
public:
	BSTNode(const char& newChar = ' ', const string& newString = " ");
	~BSTNode();
	string getString()const;
	char getChar()const;
	void setString(string newString);
	void setChar(char newChar);
	BSTNode* getLeftPtr() const;
	BSTNode* getRightPtr()const;
	void setLeftPtr(BSTNode* newPtr);
	void setRightPtr(BSTNode* newPtr);
	BSTNode(BSTNode& copyNode);
private:
	char mLetter;
	string mMorseCode;
	BSTNode* mpLeft;
	BSTNode* mpRight;
};

std::istream& operator >>(std::istream& fileStream, BSTNode& node);
