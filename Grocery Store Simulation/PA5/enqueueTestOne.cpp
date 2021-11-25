#include "enqueueTestOne.hpp"


enqueueTestOne::enqueueTestOne() {
	TestData = new Data;
	test = new Queue;
	TestData->setCustomerNumber(1);
	TestData->setserviceTime(4);
	TestData->settotalTime(4);
	
}
void runTestOne() {
	enqueueTestOne t;
	t.enqueueTestMode();
}

enqueueTestOne::~enqueueTestOne() {
	delete test;
}

void enqueueTestOne::enqueueTestMode() {
	
	test->enqueue(*TestData);

	if (test == nullptr) {
		cout << "Queue is Empty! Check Again!" << endl;
	}
	else {
		cout << "One Node has been read!" << endl;
	}
	if (test->getHeadPtr()->getData()->getCustomerNumber() == 1) {
		cout << "Customer number has been read!" << endl;
	}
	else {
		cout << "error reading numbers!!!" << endl;
	}
	if (test->getHeadPtr()->getData()->getserviceTime() == 4) {
		cout << "getserviceTime number has been read!" << endl;
	}
	else {
		cout << "error reading numbers!!!" << endl;
	}
	if (test->getHeadPtr()->getData()->gettotalTime() == 4) {
		cout << "gettotalTime number has been read!" << endl;
	}
	else {
		cout << "error reading numbers!!!" << endl;
	}

	if (test->getHeadPtr() == test->getTailPtr()) {
		cout << "Both head pointer and tail are the same!" << endl;
	}
	else {
		cout << "Error inserting in headptr and tailptr" << endl;
	}
}