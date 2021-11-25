#include "dequeueTestOne.hpp"
//constructor for testing
dequeueTestOne::dequeueTestOne() {
	TestData = new Data;
	test = new Queue;
	TestData->setCustomerNumber(1);
	TestData->setserviceTime(4);
	TestData->settotalTime(4);

	test->enqueue(*TestData);
}
void runTestOneDe() {
	dequeueTestOne T;
	T.dequeueTestMode();
}
dequeueTestOne::~dequeueTestOne() {
	//delete test;
}
//conditions for testing
void dequeueTestOne::dequeueTestMode() {
	if (test->getHeadPtr() == nullptr) {
		cout << "Queue is not supposed to be empty!" << endl;

	}
	else {
		cout << "Queue initially has one node!" << endl;
	}

	test->dequeue();

	if (test->getHeadPtr() == nullptr) {
		cout << "After dequeueing, no nodes are left!" << endl;
	}
	else {
		cout << "Error dequeueing!"<<endl;
	}
}