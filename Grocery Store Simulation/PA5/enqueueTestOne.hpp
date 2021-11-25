#include "Queue.hpp"
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;


class enqueueTestOne {
public:
	enqueueTestOne();
	~enqueueTestOne();
	void enqueueTestMode();

private:
	Queue *test;
	Data* TestData;
};

void runTestOne();
