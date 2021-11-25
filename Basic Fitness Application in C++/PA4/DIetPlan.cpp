#include "DietPlan.hpp"
/*************************************************************
 * Function: DietPlan::DietPlan()                                 *
 * Date Created:  10/6/21                                           *
 * Date Last Modified: 10/6/21                                        *
 * Description: Constructor! basic assignment of blanks and zeros for formatting                                       *
 * Returns: nothing                                               *
 * Preconditions: array should be constructed or space must be allocated                                          *
 * Postconditions:                                          *
 *************************************************************/
DietPlan::DietPlan() {
	//applies blanks or zeros, sorta default
	mPlanName = "";
	mGoalCal = 0;
	mDate = "";
}
/*************************************************************
 * Function: DietPlan::DietPlan(int newGoalCal, string newPlanName, string newDate)                                 *
 * Date Created:  10/6/21                                           *
 * Date Last Modified: 10/6/21                                        *
 * Description: Constructor! custom assignment in parameters                                    *
 * Returns: nothing                                               *
 * Preconditions: info must be valid                                         *
 * Postconditions:                                          *
 *************************************************************/
DietPlan::DietPlan(int newGoalCal, string newPlanName, string newDate) {
	//checks for invalid numbers
	if (newGoalCal < 0) {
		newGoalCal = 0;
	}
	else {
		mGoalCal = newGoalCal;

	}
	mPlanName = newPlanName;
	mDate = newDate;
}

/*************************************************************
 * Function: DietPlan::DietPlan(int newGoalCal, string newPlanName, string newDate)                                 *
 * Date Created:  10/6/21                                           *
 * Date Last Modified: 10/6/21                                        *
 * Description: Destructor! goes outside of scope, object is destroyed, garbage collector                                   *
 * Returns: nothing                                               *
 * Preconditions: object should be constructed                                         *
 * Postconditions:                                          *
 *************************************************************/
DietPlan::~DietPlan() {
	//obj out of scope
}
/*************************************************************
 * Function:DietPlan::DietPlan(DietPlan& copyDietPlan)                                *
 * Date Created:  10/6/21                                           *
 * Date Last Modified: 10/6/21                                        *
 * Description: copy construcor! can copy objs                                   *
 * Returns: nothing                                               *
 * Preconditions: object should be constructed                                         *
 * Postconditions:                                          *
 *************************************************************/
DietPlan::DietPlan(DietPlan& copyDietPlan) {
	//sets new values to data members, copying.
	mGoalCal = copyDietPlan.getGoalCal();
	mPlanName = copyDietPlan.getPlanName();
	mDate = copyDietPlan.getDate();
}
/*************************************************************
 * Function:int DietPlan::getGoalCal()const {                               *
 * Date Created:  10/6/21                                           *
 * Date Last Modified: 10/6/21                                        *
 * Description: gets int apart of info                                  *
 * Returns: goalCal                                               *
 * Preconditions: object should be constructed                                         *
 * Postconditions:                                          *
 *************************************************************/
int DietPlan::getGoalCal()const {
	return mGoalCal;
}
/*************************************************************
 * Function:int string DietPlan::getPlanName()const {                             *
 * Date Created:  10/6/21                                           *
 * Date Last Modified: 10/6/21                                        *
 * Description: gets string apart of info                                  *
 * Returns: planName                                               *
 * Preconditions: object should be constructed                                         *
 * Postconditions:                                          *
 *************************************************************/
string DietPlan::getPlanName()const {
	return mPlanName;
}
/*************************************************************
 * Function:string DietPlan::getDate()const {                             *
 * Date Created:  10/6/21                                           *
 * Date Last Modified: 10/6/21                                        *
 * Description: gets string apart of info                                  *
 * Returns: mDAte                                               *
 * Preconditions: object should be constructed                                         *
 * Postconditions:                                          *
 *************************************************************/
string DietPlan::getDate()const {
	return mDate;
}
/*************************************************************
*void DietPlan::setGoalCal(int GoalCal) {
 * Date Created:  10/6/21                                           *
 * Date Last Modified: 10/6/21                                        *
 * Description: sets int apart of info                                  *
 * Returns: nothing (assigns)                                               *
 * Preconditions: object should be constructed                                         *
 * Postconditions:                                          *
 *************************************************************/
void DietPlan::setGoalCal(int GoalCal) {
	mGoalCal = GoalCal;
}
/*************************************************************
*void void DietPlan::setPlanName(string planName) {
 * Date Created:  10/6/21                                           *
 * Date Last Modified: 10/6/21                                        *
 * Description: sets string apart of info                                  *
 * Returns: nothing (assigns)                                               *
 * Preconditions: object should be constructed                                         *
 * Postconditions:                                          *
 *************************************************************/
void DietPlan::setPlanName(string planName) {
	mPlanName = planName;
}

/*************************************************************
*voidDietPlan::setDate(string date) {
 * Date Created:  10/6/21                                           *
 * Date Last Modified: 10/6/21                                        *
 * Description: sets string apart of info                                  *
 * Returns: nothing (assigns)                                               *
 * Preconditions: object should be constructed                                         *
 * Postconditions:                                          *
 *************************************************************/
void DietPlan::setDate(string date) {
	mDate = date;
}
/*************************************************************
*void void DietPlan::editGoal() {
 * Date Created:  10/6/21                                           *
 * Date Last Modified: 10/6/21                                        *
 * Description: allows for setting new int                                 *
 * Returns: nothing (assigns)                                               *
 * Preconditions: object should be constructed                                         *
 * Postconditions:                                          *
 *************************************************************/
void DietPlan::editGoal() {
	//gets called from FAW source file, augmented from the array of objs
	int option = 0;
	cout << "**********What would you like to change your goalCal?**********" << endl;
	cin >> option;
	//setting option to obj
	this->setGoalCal(option);
	
}
/*************************************************************
*std::istream& operator >>(std::istream& fileStream, DietPlan& dietPlan) {
 * Date Created:  10/10/21                                           *
 * Date Last Modified: 10/10/21                                        *
 * Description: overloads the reading operator, meant to read from file                                  *
 * Returns: nothing (assigns)                                               *
 * Preconditions: file should be opened                                      *
 * Postconditions:                                          *
 *************************************************************/
std::istream& operator >>(std::istream& fileStream, DietPlan& dietPlan) {
	//gets line then applies it to obj
	char data[100] = "";
	fileStream.getline(data, 100);
	dietPlan.setPlanName(data);
	
	fileStream.getline(data, 100);
	dietPlan.setGoalCal(atoi(data));
	
	fileStream.getline(data, 100);
	dietPlan.setDate(data);
	fileStream.getline(data, 100);
	return fileStream;
}
/*************************************************************
*std::ostream& operator<< (std::ostream& lhs, const DietPlan& rhs) {
 * Date Created: 10/10/21                                           *
 * Date Last Modified: 10/10/21                                       *
 * Description: overloaded out stream operator, meant for displaying info                                  *
 * Returns: nothing (assigns)                                               *
 * Preconditions: object should be contructed                                         *
 * Postconditions:                                          *
 *************************************************************/
std::ostream& operator<< (std::ostream& lhs, const DietPlan& rhs) {
	//formatting operator
	lhs << " PlanName: " << rhs.getPlanName()<<" GoalCal: "<<rhs.getGoalCal() <<" Date: " << rhs.getDate() << endl;
	return lhs;
}
/*************************************************************
*std::ofstream& operator<< (std::ofstream& fileName, const DietPlan& dietPlan) {
 * Date Created: 10/10/21                                            *
 * Date Last Modified: 10/10/21                                         *
 * Description: overloads the writing operator, meant for writing                               *
 * Returns: nothing (assigns)                                               *
 * Preconditions: file should be ready to write                                     *
 * Postconditions:                                          *
 *************************************************************/
std::ofstream& operator<< (std::ofstream& fileName, const DietPlan& dietPlan) {
	//formatting operator
	fileName << dietPlan.getPlanName() << endl << dietPlan.getGoalCal() << endl << dietPlan.getDate()<<endl<<endl;

	return fileName;
}