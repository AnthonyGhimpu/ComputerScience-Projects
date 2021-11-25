#pragma once
#include <iostream>
#include "Data.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class QueueNode {
	//typical queue node class
public:
	QueueNode(const Data& pData);
	void setNextPtr(QueueNode* const pNewNext);
	QueueNode* getNextPtr()const;
	Data *getData()const;
	~QueueNode();
	
private:
	Data* pData;
	QueueNode* pNext;
};
