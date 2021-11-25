#include "QueueNode.hpp"
//constructor with mem alloc for data
QueueNode::QueueNode(const Data& newData) {
	//need to review
	this->pData = new Data;
	
	this->pData->setCustomerNumber(newData.getCustomerNumber());
	this->pData->setserviceTime(newData.getserviceTime());
	pData->settotalTime(newData.gettotalTime());
	pData->setStartNumber(newData.getStartNumber());
	pData->settotalTimePreserve(newData.gettotalTimePreserve());

	this->pNext = nullptr;
}
QueueNode::~QueueNode() {
	
	

}
//setters and getters
void QueueNode::setNextPtr(QueueNode* const pNewNext) {
	pNext = pNewNext;
}

QueueNode* QueueNode::getNextPtr()const {
	return pNext;
}
Data* QueueNode::getData() const {
	return pData;
}
