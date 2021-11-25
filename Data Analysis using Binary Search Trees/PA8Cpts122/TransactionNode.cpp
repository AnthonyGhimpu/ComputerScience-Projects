#include "TransactionNode.hpp"

TransactionNode::~TransactionNode() {

}

TransactionNode::TransactionNode(string newData, int newUnits):Node(newData) {
	mUnits = newUnits;
}
void TransactionNode::setUnits(int newUnits) {
	mUnits = newUnits;
}
int TransactionNode::getUnits()const {
	return mUnits;
}
void TransactionNode::printData() {
	//whatever obj is being passed in, we can print it
	string data = this->getData();
	int units = this->getUnits();
	cout << units << "," << data<<endl;
}
