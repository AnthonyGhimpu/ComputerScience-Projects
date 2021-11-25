#pragma once
#include "Node.hpp"
#define _CRT_SECURE_NO_WARNINGS

class TransactionNode : public Node {
public:
	~TransactionNode();
	TransactionNode(string newData = " ", int newUnits = 0);
	void setUnits(int newUnits);
	int getUnits()const;

	//must be defined
	void printData();
private:
	int mUnits;
};