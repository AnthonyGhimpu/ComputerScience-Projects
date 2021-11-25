#pragma once

#include <iostream>
#include <fstream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using std::cin;
using std::cout;
using std::endl;
#include "StackDates.hpp"
using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

class Data {
public:
	Data(int mRecordNum = 0, int mIDNum = 0, string mName = "", string mEmail = "", string mUnits = "", string mProgram = "",
		string mLevel = "", int mNumAbs = 0);
	~Data();
	Data(Data* copyData);
	//getters
	int getRecordNum();
	int getID();
	string getName();
	string getEmail();
	string getUnits();
	string getProgram();
	string getLevel();
	int getAbs();
	StackDates getStack();

	//setters
	void setRecordNum(int newRecord);
	void setID(int newID);
	void setName(string newName);
	void setEmail(string newEmail);
	void setUnits(string newUnits);
	void setProgram(string newProgram);
	void setLevel(string newLevel);
	void setAbs(int newAbs);
	void setStack(StackDates dates);
	void setPushStack(string date);

private:
	int mRecordNum;
	int mIDNum;
	string mName;
	string mEmail;
	string mUnits;
	string mProgram;
	string mLevel;
	int mNumAbs;
	StackDates *arrDates;
};