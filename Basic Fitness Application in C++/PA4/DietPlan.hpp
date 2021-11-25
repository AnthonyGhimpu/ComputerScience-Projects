#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class DietPlan {
public:
	//dietPlan constructor
	DietPlan();
	//dietPlan custom constructor
	DietPlan(int mGoalSteps, string planName, string date);
	//destructor
	~DietPlan(); //invoked when dietPlan obj goes out of scope
	//copy constructor
	DietPlan(DietPlan& copyExercisePlan);
	//getters for all DataM
	int getGoalCal()const;
	string getPlanName()const;
	string getDate()const;
	//setters for all dataM
	void setGoalCal(int goalCal);
	void setPlanName(string planName);
	void setDate(string date);
	//editing gives us access to data directly bc member function
	void editGoal();

private:
	//data members
	int mGoalCal;
	string mPlanName;
	string mDate;
};
//operator overloading
std::istream& operator >>(std::istream& fileName, DietPlan& dietPlan);
std::ostream& operator<< (std::ostream& lhs,const DietPlan& rhs);
std::ofstream& operator<< (std::ofstream& fileName, const DietPlan& dietPlan);
