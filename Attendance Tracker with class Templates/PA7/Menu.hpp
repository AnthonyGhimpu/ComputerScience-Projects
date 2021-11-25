
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

class menu {
public:
	menu();
	void displayMain();
	void displaySub();
	int getOption();
private:
	string main;
	string subMenuOne;
	int option;
};