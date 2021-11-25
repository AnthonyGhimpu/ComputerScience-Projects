#include "ExercisePlan.hpp"
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::fstream;

class FitnessAppWrapper {

public:
	//constructor, initialized two array of objects
	FitnessAppWrapper();
	void runApp(void);
	//fstream openFileDiet();
	//open file 
	fstream openDiet();
	fstream openExercise();
	//write to file
	ofstream writeExercise();
	ofstream writeDiet();



	//loading - overloaded for each type
	void loadDailyPlan(fstream& fileStream, DietPlan& plan);
	void loadDailyPlan(fstream& fileStream, ExercisePlan& plan);
	void loadWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[]);
	void loadWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[]);
	//displaying for each type
	void displayDailyPlan(DietPlan& plan, int i);
	void displayDailyPlan(ExercisePlan& plan, int i);
	void displayWeeklyPlan(DietPlan weeklyPlan[]);
	void displayWeeklyPlan(ExercisePlan weeklyPlan[]);
	//storing for each type
	void storeWeeklyPlan(ofstream& fileStream, ExercisePlan weeklyPlan[]);
	void storeWeeklyPlan(ofstream& fileStream, DietPlan weeklyPlan[]);
	void storeDailyPlan(ofstream& fileStream, ExercisePlan& plan);
	void storeDailyPlan(ofstream& fileStream, DietPlan& plan);
	//editing for each type
	void editPlan(DietPlan weeklyPlan[]);
	void editPlan(ExercisePlan weeklyPlan[]);
	//menu functions
	void displayMenu();
	int getMenuOption();

private:
	//array of objs, and file streams for writing and reading
	DietPlan* mDietPlanPtr;
	ExercisePlan* mExcersisePlanPtr;
	fstream infile;
	fstream ExInfile;
	ofstream outfile;
	ofstream Exoutfile;
};


