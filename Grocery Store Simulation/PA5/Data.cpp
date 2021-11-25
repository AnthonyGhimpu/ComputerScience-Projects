#include "Data.hpp"
//initialize the obj
Data::Data() {
	customerNumber = 0;
	serviceTime = 0;
	totalTime = 0;
	start = 0;
	totalTimePreserve = 0;
}

//initialize obj with params
Data::Data(int newCustomerNumber, int newServiceTime, int newTotalTime, int newStart, int newTotalStart) {
	
	customerNumber = newCustomerNumber;
	serviceTime = newServiceTime;
	totalTime = newTotalTime;
	start = newStart;
	totalTimePreserve = newTotalStart;
}

Data::~Data() {
	//destructor

}
//copy constructor
Data::Data(Data& copyData) {

	customerNumber = copyData.getCustomerNumber();
	serviceTime = copyData.getserviceTime();
	totalTime = copyData.gettotalTime();
	start = copyData.getStartNumber();
	totalTimePreserve = copyData.gettotalTimePreserve();
}
//getters and setters for data
int Data::getCustomerNumber() const {
	return customerNumber;
}
int Data::getserviceTime()const {
	return serviceTime;
}
int Data::gettotalTime() const {
	return totalTime;
}

void Data::setCustomerNumber(const int newCustNumb) {
	customerNumber = newCustNumb;
}
void Data::setserviceTime(const int servTime) {
	serviceTime = servTime;
}
void Data::settotalTime(const int totTime) {
	totalTime = totTime;
}

int Data::getStartNumber()const {
	return start;
}

void Data::setStartNumber(const int newStart) {
	start = newStart;
}

int Data::gettotalTimePreserve()const {
	return totalTimePreserve;
}
void Data::settotalTimePreserve(const int newtotalTimePreserve) {
	totalTimePreserve = newtotalTimePreserve;
}
