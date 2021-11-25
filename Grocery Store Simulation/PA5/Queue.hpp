#pragma once
#include <iostream>
#include "QueueNode.hpp"

using std::cin;
using std::cout;
using std::endl;

class Queue
    //class queue
    //everything is in here getters and setters
{

public: // Member functions
    Queue(QueueNode* pNewHead = nullptr, QueueNode* pNewTail = nullptr);
    bool enqueue(const Data& newData);
    bool isempty() const;
    void printQueue(Queue newQueue);
    Data dequeue();
    QueueNode *getHeadPtr();
    //Queue* subTractData(Data newData, Queue* newQueue);
    QueueNode* getTailPtr();
    void setHeadPtr(QueueNode* pHead);
    void setTailPtr(QueueNode* pHead);

    ~Queue();
    int sizeOf(Queue newQueue);
    
private:

    QueueNode* pHead;
    QueueNode* pTail;

};