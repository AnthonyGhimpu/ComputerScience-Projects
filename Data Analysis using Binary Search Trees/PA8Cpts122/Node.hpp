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

class Node {
	//abstract class, as there is one pure virtual function
public:
	virtual ~Node();
	Node(string newData);
	void setData(string newData);
	void setRightNode(Node* newRight);
	void setLeftNode(Node* newRight);
	string getData()const;
	Node*& getLeft();
	Node*& getRight();
	//pure V, if we have this function, we need to define it in every class that this class is being inherited in
	virtual void printData() = 0;
protected:
	string mData;
	Node* mpLeft;
	Node* mpRight;
	
};