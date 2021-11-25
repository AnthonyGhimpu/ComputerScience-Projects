#pragma once
#include <iostream>

//Data class
//consists of the usual member functions such as getters and setters
using std::cin;
using std::cout;
using std::endl;

class Data {
public:
    Data();
    Data(int customerNumber, int serviceTime, int totalTime, int newStart, int newTotalStart);
    ~Data();
    Data(Data& copyData);

    int getCustomerNumber()const;
    int getserviceTime()const;
    int gettotalTime()const;

    void setCustomerNumber(int newCustNumb);
    void setserviceTime(int servTime);
    void settotalTime(int totalTime);
    int getStartNumber()const;
    void setStartNumber(const int start);
    int gettotalTimePreserve()const;
    void settotalTimePreserve(const int newtotalTimePreserve);

    

  


 private:
    int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
    int serviceTime;   // Random time; varies between express and normal lanes; units in minutes=
    int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
    int start; //holds onto the the place in line when they first step in
    int totalTimePreserve;//holds onto the place in line when their time is the highest
};
