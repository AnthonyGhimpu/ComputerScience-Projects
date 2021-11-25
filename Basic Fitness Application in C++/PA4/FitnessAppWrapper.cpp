#include "FitnessAppWrapper.hpp"
FitnessAppWrapper::FitnessAppWrapper() {
	//makes two arrays full of objects
	mDietPlanPtr = new DietPlan[8];
	mExcersisePlanPtr = new ExercisePlan[8];
}

int FitnessAppWrapper::getMenuOption() {
	//gets option from user
	int option = 0;
	cin >> option;
	return option;
}
fstream FitnessAppWrapper::openDiet() {
	//opens file for diet plan
	fstream infile;
	string fileNameDiet = "dietPlans.txt";
	//reading file
	infile.open(fileNameDiet.c_str(), std::ios::in);
	if (infile.is_open()) {
		return infile;
	}
	else {
		cout << "Error opening file!" << endl;
	}
	
}

fstream FitnessAppWrapper::openExercise() {
	//opens file for exercise plan
	fstream infile;
	string fileNameDiet = "exercisePlans.txt";
	//reading file
	infile.open(fileNameDiet.c_str(), std::ios::in);
	if (infile.is_open()) {
		return infile;
	}
	else {
		cout << "Error opening file!" << endl;
	}

}

ofstream FitnessAppWrapper::writeExercise() {
	//opens file for writing
	ofstream outfile;
	string fileNameDiet = "exercisePlans.txt";
	outfile.open(fileNameDiet.c_str(), std::ios::out);
	if (outfile.is_open()) {
		return outfile;
	}
	else {
		cout << "Error  writing to file!" << endl;
	}

}


ofstream FitnessAppWrapper::writeDiet() {
	//opens file for writing
	ofstream outfile;
	string fileNameDiet = "dietPlans.txt";
	outfile.open(fileNameDiet.c_str(), std::ios::out);
	if (outfile.is_open()) {
		return outfile;
	}
	else {
		cout << "Error writing to file!" << endl;
	}

}

void FitnessAppWrapper::runApp() {
	int option = 0;
	bool status = true, success = true;

	
	
	do {
		displayMenu();
		option = getMenuOption();
		//all cases all functions corresponding to choice
		switch (option) {
		case 1:
			infile = openDiet();
			loadWeeklyPlan(infile, mDietPlanPtr);
			//infile.close();
			break;
		case 2:
			ExInfile = openExercise();
			loadWeeklyPlan(ExInfile, mExcersisePlanPtr);
			//Close???
			break;
		case 3:
			//warning for not having file open
			if (!infile.is_open()) {
				cout << "You have not opened the DIET file yet!" << endl;
				cout << "Please refer to option 1!" << endl;
				break;
			}
			//writes to file
			outfile = writeDiet();
			storeWeeklyPlan(outfile, mDietPlanPtr);
			//closes out file
			outfile.close();
			break;
		case 4:
			if (!ExInfile.is_open()) {
				cout << "You have not opened the Exercise file yet!" << endl;
				cout << "Please refer to option 2!" << endl;
				break;
			}
			
			Exoutfile = writeExercise();
			storeWeeklyPlan(Exoutfile, mExcersisePlanPtr);
			Exoutfile.close();
			break;
		case 5:
			if (!infile.is_open()) {
				cout << "You have not opened the DIET file yet!" << endl;
				cout << "Please refer to option 1!" << endl;
				break;
			}
			displayWeeklyPlan(mDietPlanPtr);
			break;
		case 6:
			if (!ExInfile.is_open()) {
				cout << "You have not opened the Exercise file yet!" << endl;
				cout << "Please refer to option 2!" << endl;
				break;
			}
			displayWeeklyPlan(mExcersisePlanPtr);
			break;
		case 7:
			if (!infile.is_open()) {
				cout << "You have not opened the DIET file yet!" << endl;
				cout << "Please refer to option 1!" << endl;
				break;
			}
			editPlan(mDietPlanPtr);
			break;
		case 8:
			if (!ExInfile.is_open()) {
				cout << "You have not opened the Exercise file yet!" << endl;
				cout << "Please refer to option 2!" << endl;
				break;
			}
			editPlan(mExcersisePlanPtr);
			break;
		case 9:
		
			//conditions for exiting program
			//if both files are open
			if ((infile.is_open()&&ExInfile.is_open())) {
				//we write to file
				//even if the user writes and stores, the case closes the write file so no collison there
				outfile = writeDiet();
				Exoutfile = writeExercise();
				//store
				storeWeeklyPlan(outfile, mDietPlanPtr);
				storeWeeklyPlan(Exoutfile, mExcersisePlanPtr);
			}
			//if one's is open and the other is not,  then we open the file for the corresponding one and write.
			//other file is irrelevent
			else if (infile.is_open() && !ExInfile.is_open()) {
				outfile = writeDiet();
				storeWeeklyPlan(outfile, mDietPlanPtr);
			
			}
			//if one's is open and the other is not,  then we open the file for the corresponding one and write.
			//other file is irrelevent
			else if (!infile.is_open() && ExInfile.is_open()) {
				Exoutfile = writeExercise();
				storeWeeklyPlan(Exoutfile, mExcersisePlanPtr);
			
			}
			else {
				//if none of them are open, then we open and load all info
				//this needs to be done because we are going to store garbage values 
				infile = openDiet();
				loadWeeklyPlan(infile, mDietPlanPtr);
				ExInfile = openExercise();
				loadWeeklyPlan(ExInfile, mExcersisePlanPtr);
				//then write and store
				outfile = writeDiet();
				Exoutfile = writeExercise();
				storeWeeklyPlan(outfile, mDietPlanPtr);
				storeWeeklyPlan(Exoutfile, mExcersisePlanPtr);
			}
			//close all files no matter what
			outfile.close();
			Exoutfile.close();
			infile.close();
			ExInfile.close();
			status = false;
		} 
	} while (status != false);
	cout << "Thanks for using the Fitness App!" << endl;
	exit(0);
}
void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[]) {
	
	if (fileStream.is_open()) // did the file open successfully?
	{//no need for EOF, that is because the overloaded op function already does the job
			//	string data;
			for (int i = 1; i <= 7; i++) {
				//load plan 7 times
				loadDailyPlan(fileStream, weeklyPlan[i]);
				}
		}
	}



void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[]) {
	if (fileStream.is_open()) // did the file open successfully?
	{
		//same thing here
			//	string data;
			for (int i = 1; i <= 7; i++) {
				loadDailyPlan(fileStream, weeklyPlan[i]);
		}
	}
}

void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, DietPlan& plan) {
	//filestream info goes into plan, op is overloaded, meaning we will call the corresponding function
	fileStream >> plan;
}
void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, ExercisePlan& plan) {
	//filestream info goes into plan, op is overloaded, meaning we will call the corresponding function
	fileStream >> plan;
}


void FitnessAppWrapper::displayDailyPlan(DietPlan& plan, int i) {
	//for displaying, operator function will display info from obj by 1
		cout << i << ":" << plan << endl;
	
}
void FitnessAppWrapper::displayDailyPlan(ExercisePlan& plan, int i) {
	//for displaying, operator function will display info from obj by 1
	cout << i << ":" << plan << endl;

}

void FitnessAppWrapper::displayWeeklyPlan(DietPlan weeklyPlan[]) {
	cout << "*********Your Weekly DietPlan*********" << endl;
	//loops and calls dailyPlan one at a time
	for (int i = 1; i <= 7; i++) {
		displayDailyPlan(weeklyPlan[i], i);
	}
}
void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan weeklyPlan[]) {
	cout << "*********Your Weekly ExercisePlan*********" << endl;
	//loops and calls dailyPlan one at a time
	for (int i = 1; i <= 7; i++) {
		displayDailyPlan(weeklyPlan[i], i);
	}
}

void FitnessAppWrapper::storeWeeklyPlan(ofstream& fileStream, DietPlan weeklyPlan[]) {
	//loops and calls store daily plan 7 times
	for (int i = 1; i <= 7; i++) {
		storeDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::storeWeeklyPlan(ofstream& fileStream, ExercisePlan weeklyPlan[]) {
	//loops and calls store daily plan 7 times
	for (int i = 1; i <= 7; i++) {
		storeDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::storeDailyPlan(ofstream& fileStream, ExercisePlan& plan) {
	//overloaded operator yet again, used for writing to file. To differentiate, we look at the parameters (ofStream vs fstream) and also types of objects
	fileStream << plan;
}
void FitnessAppWrapper::storeDailyPlan(ofstream& fileStream, DietPlan& plan) {
	//overloaded operator yet again, used for writing to file. To differentiate, we look at the parameters
	fileStream << plan;
}

void FitnessAppWrapper::editPlan(DietPlan weeklyPlan[]) {
	//choose which plan
	displayWeeklyPlan(mDietPlanPtr);
	cout << "Which plan would you like to change?" << endl;
	int option = 0;
	option = getMenuOption();
	//display one plan
	displayDailyPlan(weeklyPlan[option], option);
	//here we call editGoal apart of dietPlan class and we can do that because we have the pos where the obj is being edited, which is part dietPlan
	weeklyPlan[option].editGoal();
	system("cls");
	cout << "New Plan! Looks good!" << endl;
	displayDailyPlan(weeklyPlan[option], option);
}
void FitnessAppWrapper::editPlan(ExercisePlan weeklyPlan[]) {
	//same thing here
	displayWeeklyPlan(mExcersisePlanPtr);
	cout << "Which plan would you like to change?" << endl;
	int option = 0;
	option = getMenuOption();
	displayDailyPlan(weeklyPlan[option], option);
	weeklyPlan[option].editGoal();
	system("cls");
	cout << "New Plan! Looks good!" << endl;
	displayDailyPlan(weeklyPlan[option], option);
}


void FitnessAppWrapper::displayMenu() {
	cout << "1. Load weekly diet plan from file." << endl;
	cout << "2. Load weekly exercise plan from file." << endl;
	cout << "3. Store weekly diet plan to file." << endl;
	cout << "4. Store weekly exercise plan to file" << endl;
	cout << "5. Display weekly diet plan to screen." << endl;
	cout << "6. Display weekly exercise plan to screen." << endl;
	cout << "7. Edit daily diet plan." << endl;
	cout << "8. Edit daily exercise plan." << endl;
	cout << "9. Exit." << endl;

}
