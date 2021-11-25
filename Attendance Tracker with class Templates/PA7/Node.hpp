#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Data.hpp"
#define _CRT_SECURE_NO_WARNINGS
using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

template <class T>
class Node {
public:
	T getData();
	Node(T newData);
	~Node();
	Node<T>* getNextPtr();
	void setData(T newData);
	void setNextPtr(Node<T>* newPtr);
	void setAbsNode(int newData);

private:
	T mData;
	Node<T>* pNext;
};
template<class T>
Node<T>::~Node() {

}

template<class T>
T Node<T>::getData() {
	return mData;
}
template<class T>
Node<T>::Node(T newData) {
	this->pNext = nullptr;
	this->mData = newData;
}
template<class T>
Node<T>* Node<T>::getNextPtr() {
	return this->pNext;
}

template<class T>
void Node<T>::setNextPtr(Node<T>* newPtr){
	this->pNext = newPtr;
}

template<class T>
void Node<T>::setData(T newData) {
	mData = newData;
}
template<class T>
void Node<T>::setAbsNode(int newData) {
	mData.setAbs(newData);
}

