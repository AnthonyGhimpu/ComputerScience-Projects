#include "dequeueTestTwo.hpp"

dequeueTestTwo::dequeueTestTwo() {
	TestData = new Data;
	testDataTwo = new Data;
	test = new Queue;
	TestData->setCustomerNumber(1);
	TestData->setserviceTime(4);
	TestData->settotalTime(4);

	testDataTwo->setCustomerNumber(2);
	testDataTwo->setserviceTime(5);
	testDataTwo->settotalTime(5);

	test->enqueue(*TestData);
	test->enqueue(*testDataTwo);

}
void runTestTwoDe() {
	dequeueTestTwo T;
	T.dequeueTestModeTwo();
}
dequeueTestTwo::~dequeueTestTwo() {

}

void dequeueTestTwo::dequeueTestModeTwo() {
	if (test->getHeadPtr() != test->getTailPtr()) {
		cout << "Nodes are correctly initialized" << endl;
	}
	else {
		cout << "Something is wrong with the initialization!" << endl;
	}
	test->dequeue();

	if (test == nullptr) {
		cout << "Queue is Empty! Check Again!" << endl;
	}
	else {
		cout << "One Node has been read!" << endl;
	}
	if (test->getHeadPtr()->getData()->getCustomerNumber() == 2) {
		cout << "Customer number has been read!" << endl;
	}
	else {
		cout << "error reading numbers!!!" << endl;
	}
	if (test->getHeadPtr()->getData()->getserviceTime() == 5) {
		cout << "getserviceTime number has been read!" << endl;
	}
	else {
		cout << "error reading numbers!!!" << endl;
	}
	if (test->getHeadPtr()->getData()->gettotalTime() == 5) {
		cout << "gettotalTime number has been read!" << endl;
	}
	else {
		cout << "error reading numbers!!!" << endl;
	}

	if (test->getHeadPtr() == test->getTailPtr()) {
		cout << "Both head pointer and tail are the same!" << endl;
	}
	else {
		cout << "Error detecting similar position for headptr and tailptr" << endl;
	}
	if (test->sizeOf(*test) == 1) {
		cout << "correct amount of nodes 1!" << endl;
	}
	else {
		cout << "incorrect amount of nodes" << endl;
	}
}
