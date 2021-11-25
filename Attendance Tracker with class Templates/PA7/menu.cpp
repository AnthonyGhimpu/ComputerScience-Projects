#include "Menu.hpp"


menu::menu() {
	main = "1. Import course list\n 2. Load master list\n 3. Store master list\n 4. Mark absences\n 5. Generate report\n 6. Exit\n";
	subMenuOne = " 1. Generate report for all students \n 2. Generate report for students with absences that match or exceed (the number entered by the user).\n";
	option = 0;
}
void menu::displayMain() {
	cout << main << endl;
}
void menu::displaySub() {
	cout << subMenuOne << endl;
}
int menu::getOption() {
	cin >> option;
	return option;
}