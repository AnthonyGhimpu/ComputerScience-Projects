#include "Node.hpp"
 Node::~Node() {

}
Node::Node(string newData) {
	this->mData = newData;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

void Node::setData(string newData) {
	mData = newData;
}
void Node::setRightNode(Node* newRight) {
	mpRight = newRight;
}
void Node::setLeftNode(Node* newLeft) {
	mpLeft = newLeft;
}
string Node::getData()const {
	return mData;
}
Node*& Node::getLeft() {
	return mpLeft;

}
Node*& Node::getRight() {
	return mpRight;
}