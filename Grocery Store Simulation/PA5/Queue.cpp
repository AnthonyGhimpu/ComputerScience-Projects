#include "Queue.hpp"
//constructor
Queue::Queue(QueueNode* pNewHead, QueueNode* pNewTail)
{
	pHead = pNewHead;
pTail = pNewTail;
}
Queue::~Queue() {

}
//enqueue by the book
bool Queue::enqueue(const Data& newData) {
	QueueNode* pMem = new QueueNode(newData);
	bool success = false;

	if (pMem != nullptr) {
		success = true;

		if (pHead == nullptr) {
			pHead = pTail = pMem;
		}
		else {
			pTail->setNextPtr(pMem);
			pTail = pMem;
		}
	}
	return success;
}
//print queue recur
void Queue::printQueue(Queue newQueue){
	QueueNode *pCur = newQueue.pHead;
	if (pCur != nullptr) {
		cout << "Customer Number: " << pCur->getData()->getCustomerNumber() << endl;
		cout << "Service Time: " << pCur->getData()->getserviceTime() << endl;
		cout << "Total Time: " << pCur->getData()->gettotalTime() << endl<<endl;
		pCur = pCur->getNextPtr();
		printQueue(pCur);
	}
	else {
		cout << "End of Line" << endl;
	}
}

//dequeue by the book
Data Queue::dequeue() {
	QueueNode* pTemp = pHead;
	Data *returnData;

	if (pHead == pTail) {
		pHead = pTail = nullptr;
	}
	else {
		pHead = pHead->getNextPtr();
	}
	returnData = pTemp->getData();
	delete pTemp;
	
	return *(returnData);
}
//bool statement for is empty
bool Queue::isempty()const {
	return pHead == nullptr;
}
//getters and setters
QueueNode *Queue::getHeadPtr() {
	return pHead;
}

QueueNode* Queue::getTailPtr() {
	return pTail;
}
void Queue::setHeadPtr(QueueNode* pNewHead) {
	pHead = pNewHead;
}
void Queue::setTailPtr(QueueNode* pNewTail) {
	pTail = pNewTail;
}
//finding size
int Queue::sizeOf(Queue newQueue) {
	QueueNode* pCur = newQueue.pHead;
	int count = 0;
	if (pCur != nullptr) {
		while (pCur != nullptr) {
			pCur = pCur->getNextPtr();
			count++;
		}
	}
	else {
		return 0;
	}
	return count;
}