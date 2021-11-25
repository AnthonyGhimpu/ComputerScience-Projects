#include "Queue.hpp"
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//test function
class dequeueTestOne {
public:
	dequeueTestOne();
	~dequeueTestOne();
	void dequeueTestMode();

private:
	Queue* test;
	Data* TestData;
};
//non member run function
void runTestOneDe();
