#include "Data.hpp"
#define _CRT_SECURE_NO_WARNINGS
Data::Data(int	newMRecordNum, int newmIDNum,string newmName ,string newmEmail ,string newmUnits, string newmProgram, string newmLevel, int newmNumAbs) {
	 mRecordNum = newMRecordNum;
		 mIDNum = newmIDNum;
		 mName = newmName;
		 mEmail = newmEmail;
		 mUnits = newmUnits;
		 mProgram = newmProgram;
		 mLevel = newmLevel;
		 mNumAbs = newmNumAbs;
	 arrDates = new StackDates;
}
Data::~Data() {
//inside destructor
	 
}
Data::Data(Data* copyData) {
	mRecordNum = copyData->getRecordNum();
	mIDNum = copyData->getID();
	mName = copyData->getName();
	mEmail = copyData->getEmail();
	mUnits = copyData->getUnits();
	mProgram = copyData->getProgram();
	mLevel = copyData->getName();
	mNumAbs = copyData->getAbs();


}
//getters
int Data::getRecordNum() {
	return mRecordNum;
}
int Data::getID() {
	return mIDNum;
}
string Data::getName() {
	return mName;
}
string Data::getEmail() {
	return mEmail;
}
string Data::getUnits() {
	return mUnits;
}
string Data::getProgram() {
	return mProgram;
}
string Data::getLevel() {
	return mLevel;
}
int Data::getAbs() {
	return mNumAbs;
}
StackDates Data::getStack() {
	return *arrDates;
}

//setters
void Data::setRecordNum(int newRecord) {
	mRecordNum = newRecord;
}
void Data::setID(int newID) {
	mIDNum = newID;
}
void Data::setName(string newName) {
	mName = newName;
}
void Data::setEmail(string newEmail) {
	mEmail = newEmail;
}
void Data::setUnits(string newUnits) {
	mUnits = newUnits;
}
void Data::setProgram(string newProgram) {
	mProgram = newProgram;
}
void Data::setLevel(string newLevel) {
	mLevel = newLevel;
}
void Data::setAbs(int newAbs) {
	mNumAbs = newAbs;
}
//Stack getStack();
void Data::setStack(StackDates dates) {
	*(arrDates) = dates;
}
void Data::setPushStack(string date) {
	arrDates->push(date);
}