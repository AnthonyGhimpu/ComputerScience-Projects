#include "masterList.hpp"
#include "Menu.hpp"
#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;



class runMasterList {
public:
	void runProg();
	string getDate();
	fstream openFileClassList();
	fstream openMasterList();
	ofstream openOutMaster();
	masterList<Data>& markAbsences(masterList<Data>& List);
	ofstream openOutReportOne();
	ofstream openOutReportTwo();

	void writeReportOne(std::ostream& lhs, masterList<Data>& List);
	void writeReportTwo(std::ostream& lhs, masterList<Data>& List, int option);


	int countMaster(masterList<Data>& List);
	

};