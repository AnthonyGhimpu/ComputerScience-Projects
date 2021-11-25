#include "enqueueTestTwo.hpp"


enqueueTestTwo::enqueueTestTwo() {
	TestData = new Data;
	TestDataTwo = new Data;
	testTwo = new Queue;
	TestData->setCustomerNumber(1);
	TestData->setserviceTime(4);
	TestData->settotalTime(4);

	TestDataTwo->setCustomerNumber(2);
	TestDataTwo->setserviceTime(5);
	TestDataTwo->settotalTime(5);

	testTwo->enqueue(*TestData);

}
void runTestTwo() {
	enqueueTestTwo t;
	t.enqueueTestModeTwo();
}

enqueueTestTwo::~enqueueTestTwo() {
	delete testTwo;
	
}

void enqueueTestTwo::enqueueTestModeTwo() {

	testTwo->enqueue(*TestDataTwo);

	if (testTwo == nullptr) {
		cout << "Queue is Empty! Check Again!" << endl;
	}
	else {
		cout << "Some Nodes have been read!" << endl;
	}
	if (testTwo->getHeadPtr()->getData()->getCustomerNumber() == 1 && testTwo->getTailPtr()->getData()->getCustomerNumber() == 2) {
		cout << "Customer number has been read!" << endl;
	}
	else {
		cout << "error reading numbers!!!" << endl;
	}
	if (testTwo->getHeadPtr()->getData()->getserviceTime() == 4 && testTwo->getTailPtr()->getData()->getserviceTime() == 5) {
		cout << "getserviceTime number has been read!" << endl;
	}
	else {
		cout << "error reading numbers!!!" << endl;
	}
	if (testTwo->getHeadPtr()->getData()->gettotalTime() == 4 && testTwo->getTailPtr()->getData()->gettotalTime() == 5) {
		cout << "gettotalTime number has been read!" << endl;
	}
	else {
		cout << "error reading numbers!!!" << endl;
	}

	if (testTwo->getHeadPtr() != testTwo->getTailPtr()) {
		cout << "Both head pointer and tail are different!" << endl;
	}
	else {
		cout << "Error inserting in headptr or tailptr" << endl;
	}

	if (testTwo->sizeOf(*testTwo) == 2) {
		cout << "Correct amt of nodes! Two!" << endl;
	}
	else {
		cout << "wrong number of nodes!" << endl;
	}
}