#include "Queue.hpp"
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;


class dequeueTestTwo {
public:
	dequeueTestTwo();
	~dequeueTestTwo();
	void dequeueTestModeTwo();

private:
	Queue* test;
	Data* TestData;
	Data* testDataTwo;
};

void runTestTwoDe();
