#define _CRT_SECURE_NO_WARNINGS
#include "DataAnalysis.hpp"


void DataAnalysis::runAnalysis() {
	openFile();
	readFile();
	cout << endl << endl;
	trendWriting();
}

void DataAnalysis::openFile() {

	string fileNameMorse = "data.csv";
	//reading file
	mCsvStream.open(fileNameMorse.c_str(), std::ios::in);
	if (mCsvStream.is_open()) {
	
	}
	else {
		cout << "Error opening file!" << endl;
	}

}
//refs might not be needed but oh well
void DataAnalysis::splitInfo(int &units, string& item, string& sOrp) {
	char data[1000] = "";
	mCsvStream.getline(data, 1000);
	units = atoi(strtok(data, ","));
	item = strtok(NULL, ",");
	sOrp = strtok(NULL, ",");

}

void DataAnalysis::readFile() {
	int units = 0;
	string item = "";
	string sOrp = "";
	while (!mCsvStream.eof()) {
		splitInfo(units, item, sOrp);
		compareTransactionField(units, item, sOrp);
		
	}
	cout << "**********Purchased Tree**********" << endl;
	mTreePurchased.inOrderTraversal();
	cout << endl;
	cout << "**********Sold Tree**********" << endl;
	mTreeSold.inOrderTraversal();
}
void DataAnalysis::compareTransactionField(int units, string item, string sOrp) {
	if (sOrp == "Purchased") {
		mTreePurchased.insert(units, item);
	}
	else if (sOrp == "Sold") {
		mTreeSold.insert(units, item);
	}
}

void DataAnalysis::trendWriting() {
	TransactionNode tempSmall;
	TransactionNode tempMost;
	cout << "**********Units and types least sold********** " << endl;
	tempSmall = mTreeSold.findSmallest();
	cout << tempSmall.getUnits() << "," << tempSmall.getData()<<endl;

	cout << "**********Units and types Most sold********** " << endl;
	tempMost = mTreeSold.findLargest();
	cout << tempMost.getUnits() << "," << tempMost.getData() << endl;

	cout << "**********Units and types least Purchased********** " << endl;
	tempSmall = mTreePurchased.findSmallest();
	cout << tempSmall.getUnits() << "," << tempSmall.getData() << endl;

	cout << "**********Units and types Most Purchased********** " << endl;
	tempMost = mTreePurchased.findLargest();
	cout << tempMost.getUnits() << "," << tempMost.getData() << endl;
}