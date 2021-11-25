#include "Queue.hpp"
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;


class enqueueTestTwo {
public:
	enqueueTestTwo();
	~enqueueTestTwo();
	void enqueueTestModeTwo();

private:
	Queue* testTwo;
	Data* TestData;
	Data* TestDataTwo;
};

void runTestTwo();
