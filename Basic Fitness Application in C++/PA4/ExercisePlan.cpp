#include "ExercisePlan.hpp"
//*********all comments are exactly the same as DietPlan class***************
ExercisePlan::ExercisePlan() {
	mGoalSteps = 0;
	mPlanName = "";
	mDate = "";
}

ExercisePlan::ExercisePlan(int newGoalSteps, string newPlanName, string newDate) {
	if (newGoalSteps < 0) {
		newGoalSteps = 0;
	}
	else {
		mGoalSteps = newGoalSteps;

	}
	mPlanName = newPlanName;
	mDate = newDate;
}


ExercisePlan::~ExercisePlan() {

}

ExercisePlan::ExercisePlan(ExercisePlan& copyExercisePlan) {
	mGoalSteps = copyExercisePlan.getGoalSteps();
	mPlanName = copyExercisePlan.getPlanName();
	mDate = copyExercisePlan.getDate();
}

int ExercisePlan::getGoalSteps()const {
	return mGoalSteps;
}

string ExercisePlan::getPlanName()const {
	return mPlanName;
}

string ExercisePlan::getDate()const {
	return mDate;
}

void ExercisePlan::setGoalSteps(int goalSteps) {
	mGoalSteps = goalSteps;
}

void ExercisePlan::setPlanName(string planName) {
	mPlanName = planName;
}


void ExercisePlan::setDate(string date) {
	mDate = date;
}
void ExercisePlan::editGoal() {
	int option = 0;
	cout << "**********What would you like to change your goalCal?**********" << endl;
	cin >> option;
	if (option > 0) {
		this->setGoalSteps(option);
	}
	else {
		cout << "Invalid option! Type a positive Integer!" << endl;
		editGoal();
	}
}

std::istream& operator >>(std::istream& fileStream, ExercisePlan& exercisePlan) {
	char data[100] = "";
	fileStream.getline(data, 100);
	exercisePlan.setPlanName(data);

	fileStream.getline(data, 100);
	exercisePlan.setGoalSteps(atoi(data));

	fileStream.getline(data, 100);
	exercisePlan.setDate(data);
	fileStream.getline(data, 100);
	return fileStream;
}

std::ostream& operator<< (std::ostream& lhsEx, const ExercisePlan& rhsEx) {
	lhsEx << " PlanName: " << rhsEx.getPlanName() << " GoalSteps: " << rhsEx.getGoalSteps() << " Date: " << rhsEx.getDate() << endl;
	return lhsEx;
}

std::ofstream& operator<< (std::ofstream& fileName, const ExercisePlan& exercisePlan) {
	
	(std::ostream&)fileName << exercisePlan.getPlanName() << endl << exercisePlan.getGoalSteps() << endl << exercisePlan.getDate() << endl << endl;
	
	return fileName;
}