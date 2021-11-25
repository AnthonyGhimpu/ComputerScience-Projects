#include "BST.hpp"
#define _CRT_SECURE_NO_WARNINGS

class DataAnalysis {
public:
	void runAnalysis();

private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;
	void openFile();
	void splitInfo(int &units, string &item, string &sOrp);
	void readFile();
	void compareTransactionField(int units, string item, string sOrp);
	void trendWriting();
};