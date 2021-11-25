#include "BSTNode.hpp"

BSTNode::BSTNode(const char& newChar, const string& newString) {
	this->mLetter = newChar;
	this->mMorseCode = newString;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

BSTNode::~BSTNode() {

}
BSTNode::BSTNode(BSTNode& copyNode) {
	mMorseCode = copyNode.getString();
	mLetter = copyNode.getChar();
	mpLeft = copyNode.getLeftPtr();
	mpRight = copyNode.getRightPtr();
}

string BSTNode::getString()const {
	return mMorseCode;
}

char BSTNode::getChar()const {
	return mLetter;
}
void BSTNode::setString(string newString) {
	mMorseCode = newString;
}
void BSTNode::setChar(char newChar) {
	mLetter = newChar;
}

BSTNode* BSTNode::getLeftPtr() const {
	return mpLeft;
}

BSTNode* BSTNode::getRightPtr()const {
	return mpRight;
}

void BSTNode::setLeftPtr(BSTNode* newPtr) {
	mpLeft = newPtr;
}

void BSTNode::setRightPtr(BSTNode* newPtr) {
	mpRight = newPtr;
}

std::istream& operator >> (std::istream& fileStream, BSTNode& node) {
	char data[100] = "";
	fileStream.getline(data, 100);
	node.setChar(*data);
	fileStream.getline(data, 100);
	node.setString(data);
	return fileStream;
}

