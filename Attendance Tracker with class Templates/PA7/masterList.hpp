#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

#include "Node.hpp"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

template<class T>
class masterList {
public:
	masterList();
	~masterList();
	Node<T>* getHead();
	void setHead(Node<T>* newHead);
	//all adts
	void insertAtFront(T newData);
	//int countMaster(Node<T>* mpHead);

private:
	Node<T>* mpHead;
};
template<class T>
masterList<T>::~masterList() {

}
template<class T>
masterList<T>::masterList() {
	mpHead = nullptr;
}
template<class T>
Node<T>* masterList<T>::getHead() {
	return mpHead;
}
template<class T>
void masterList<T>::setHead(Node<T>* newHead) {
	mpHead = newHead;
}
template<class T>
void masterList<T>::insertAtFront(T newData) {
	Node<T>* pMem = new Node<T>(newData);
	Node<T>* pCur = mpHead;
	if (pCur == nullptr) {
		mpHead = pMem;
	}
	else {
		pMem->setNextPtr(pCur);
		mpHead = pMem;
	}
}
template<class T>
std::istream& operator >>(std::istream &classList, masterList<T>& List) {
	char data[1000] = "";
	char date[1000] = "";
	StackDates temp;
	Data buf;
		classList.getline(data, 1000);
		buf.setRecordNum(atoi(strtok(data, ",")));
		buf.setID(atoi(strtok(NULL, ",")));
		buf.setName(strtok(NULL, "\""));
		buf.setEmail(strtok(NULL, ","));
		buf.setUnits(strtok(NULL, ","));
		buf.setProgram(strtok(NULL, ","));
		buf.setLevel(strtok(NULL, ","));
	
		for (int i = 0; i <= 999; i++) {
			if (data[i] == '-') {
				buf.setAbs(atoi(strtok(NULL, ",")));
				char *var;
				var = strtok(NULL, ",");
				while (var != NULL) {
					temp.push(var);
					var = strtok(NULL, ",");
					i = 1000;
				}

			}
		}
			//classList.getline(data, 1000);
		if (!temp.isEmpty()) {
			buf.setStack(temp);
			
	}
		List.insertAtFront(buf);

		return classList;
}


template<class T>
std::ostream& operator <<(std::ostream& lhs, masterList<T>& List) {
	Node<Data>* pCur = List.getHead();
	
	
	while (pCur != nullptr) {
		if (pCur->getNextPtr() != nullptr) {
			lhs << pCur->getData().getRecordNum() << "," << pCur->getData().getID() << "," << "\"" << pCur->getData().getName() << "\"" << "," << pCur->getData().getEmail() << "," << pCur->getData().getUnits() << "," << pCur->getData().getProgram() << "," << pCur->getData().getLevel() << "," << pCur->getData().getAbs();
			if (!pCur->getData().getStack().isEmpty()) {
				StackDates tempOne;
				StackDates tempTwo;
				tempOne = pCur->getData().getStack();
				tempTwo = pCur->getData().getStack().invert(tempOne);
				
				pCur = pCur->getNextPtr();
				while (tempTwo.isEmpty() != true) {
					lhs << "," << tempTwo.pop();
					if (tempTwo.isEmpty()) {

						lhs<<endl;
					}
				}
				
			}
			else {
				lhs << endl;
				pCur = pCur->getNextPtr();
			}
		}
		else {
			lhs << pCur->getData().getRecordNum() << "," << pCur->getData().getID() << "," << "\"" << pCur->getData().getName() << "\"" << "," << pCur->getData().getEmail() << "," << pCur->getData().getUnits() << "," << pCur->getData().getProgram() << "," << pCur->getData().getLevel() << "," << pCur->getData().getAbs();
			if (!pCur->getData().getStack().isEmpty()) {
				StackDates tempOne;
				StackDates tempTwo;
				 tempOne = pCur->getData().getStack();
				 tempTwo = pCur->getData().getStack().invert(tempOne);
				pCur = pCur->getNextPtr();
				while (tempTwo.isEmpty() != true) {
					lhs << "," << tempTwo.pop();
				}
			}
			else {
				return lhs;
			}
		}
		
	}
	return lhs;
}

