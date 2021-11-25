#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include "Queue.hpp"


using std::cin;
using std::cout;
using std::endl;

//this class runs the program
class runLine {
public:
	runLine();
	
	bool runApp();
	int getAmtMinsExpress();
	int getAmtMinsNormal();
	~runLine();


	//implemented test functions inside of the main class
	int getUserMins();
	void setUserMinsTest(int minsTest);

	
private:
	Queue *NormalLine;
	Queue *ExpressLine;
	//for test case and getting a hold of the mins
	int mins;
};