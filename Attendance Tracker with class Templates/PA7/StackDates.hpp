#pragma once

#include <iostream>
#include <fstream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

class StackDates {
public:
	StackDates();
	~StackDates();
	StackDates(StackDates& copy);
	bool isEmpty();
	void push(string date);
	string peek();
	string pop();
	StackDates invert(StackDates dates);
	int countDates(StackDates dates);
private:
	int front;
	string arr[365];
};