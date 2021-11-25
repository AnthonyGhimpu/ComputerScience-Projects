#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "DietPlan.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

class ExercisePlan {
public:
	//same setup as diet plan - different context
	//comments are similar
	ExercisePlan();
	ExercisePlan(int mGoalSteps, string planName, string date);
	~ExercisePlan(); //invoked when dietPlan obj goes out of scope
	ExercisePlan(ExercisePlan& copyExercisePlan);
	int getGoalSteps()const;
	string getPlanName()const;
	string getDate()const;

	void setGoalSteps(int goalSteps);
	void setPlanName(string planName);
	void setDate(string date);
	void editGoal();

private:
	int mGoalSteps;
	string mPlanName;
	string mDate;
};
std::istream& operator >>(std::istream& fileStream, ExercisePlan& exercisePlan);
std::ostream& operator<< (std::ostream& lhsEx, const ExercisePlan& rhsEx);
std::ofstream& operator<< (std::ofstream& fileName, const ExercisePlan& dietPlan);
