#include "runMasterList.hpp"

void runMasterList::runProg() {
	menu Bruh;
	int option;
	
	bool status = true;
	masterList<Data> mainList;
	fstream infileClassList;
	fstream masterListFile;
	ofstream outMaster;
	ofstream subReportOne;
	ofstream subReportTwo;
	int count = 0;
	do {
		Bruh.displayMain();
		option = Bruh.getOption();
		switch (option) {
			
		case 1:
			
			infileClassList = openFileClassList();
			while (!infileClassList.eof()) {
				infileClassList >> mainList;
			}
			infileClassList.close();
			cout << "Successfully opened and imported CLASSLIST\n";
			break;
		case 2:
			masterListFile = openMasterList();
			while (!masterListFile.eof()) {
				masterListFile >> mainList;
			}
			masterListFile.close();
			cout << "Successfully opened and imported masterList\n";
			break;
		case 3:
			if (mainList.getHead() == nullptr) {
				cout << "Your list has not entries! Please select import MasterList or courseList!" << endl;
			}
			else {
				outMaster = openOutMaster();
				count = countMaster(mainList);
				outMaster << mainList;
				outMaster.close();
				cout << "Successfully stored masterList\n";
				break;
			}
		 
		case 4:
			if (mainList.getHead() == nullptr) {
				cout << "Your list has not entries! Please select import MasterList!" << endl;
			}
			else {
				markAbsences(mainList);
				break;
			}
			
		case 5:
			if (mainList.getHead() == nullptr) {
				cout << "Your list has not entries! Please select import MasterList!" << endl;
			}
			else {
				Bruh.displaySub();
				option = Bruh.getOption();
				if (option == 1) {
					subReportOne = openOutReportOne();
					writeReportOne(subReportOne, mainList);
					subReportOne.close();
				}
				else if (option == 2) {
					subReportTwo = openOutReportTwo();
					cout << "What threshold of absences would you like to display?\n";
					cin >> option;
					writeReportTwo(subReportTwo, mainList, option);
					subReportTwo.close();
				}
				else {
					cout << "Invalid number! Going back to main menu\n";
				}
				break;
			}
			
		case 6:
			if (mainList.getHead() != nullptr) {
				cout << "Would you like to save your list?" << endl;
				cout << "Y OR N" << endl;
				string ans;
				cin >> ans;
				if (ans == "Y") {
					outMaster = openOutMaster();
					count = countMaster(mainList);
					outMaster << mainList;
					outMaster.close();
					cout << "Successfully stored masterList\n";
					cout << "Exiting Program" << endl;
					exit(0);
				}
				else {
					cout << "Exiting Program" << endl;
					exit(0);
				}

			}
			
			break;
		}
	} while (status != false);
}

fstream runMasterList::openFileClassList() {
	fstream infile;
	string fileName = "ClassList.csv";
	infile.open(fileName.c_str(), std::ios::in);
	if (infile.is_open()) {
		return infile;
	}
	else {
		cout << "Error opening file!" << endl;
	}
}
int runMasterList::countMaster(masterList<Data>& List) {
	Node<Data>* pCur = List.getHead();
	int i = 1;
	while (pCur != nullptr) {
		pCur = pCur->getNextPtr();
		i++;
	}
	return i;
}
ofstream runMasterList::openOutReportTwo() {
	ofstream outfile;
	string fileName = "ReportTwo.txt";
	outfile.open(fileName.c_str(), std::ios::out);
	if (outfile.is_open()) {
		return outfile;
	}
	else {
		cout << "Error writing to file!" << endl;
	}

}
void runMasterList::writeReportTwo(std::ostream& lhs, masterList<Data>& List, int option) {
	Node<Data>* pCur = List.getHead();
	lhs << "Students with Greater than " << option << " Absences" << endl;
	while (pCur != nullptr) {
		if (pCur->getData().getAbs() >= option) {
			lhs << pCur->getData().getName() << endl;
			pCur = pCur->getNextPtr();
		}
		else {
			pCur = pCur->getNextPtr();
		}

	}
}

void runMasterList::writeReportOne(std::ostream& lhs, masterList<Data>& List) {
	Node<Data>* pCur = List.getHead();

	while (pCur != nullptr) {
			lhs << pCur->getData().getID() << "," << pCur->getData().getName() << "," << pCur->getData().getEmail() << ","  << pCur->getData().getProgram() << endl;
			if (pCur->getData().getStack().peek() == "") {
				lhs << "Number of absences: " << pCur->getData().getAbs() << "  Most recent date absent: " << "NO DATES " << endl;
			}
			else {
				lhs << "Number of absences: " << pCur->getData().getAbs() << "  Most recent date absent: " << pCur->getData().getStack().peek() << endl;
			}
			pCur = pCur->getNextPtr();
	}

	cout << "Successfully generated report for all students!\n" << endl;
}

ofstream runMasterList::openOutMaster() {
	ofstream outfile;
	string fileName = "masterList.txt";
	outfile.open(fileName.c_str(), std::ios::out);
	if (outfile.is_open()) {
		return outfile;
	}
	else {
		cout << "Error writing to file!" << endl;
	}

}
ofstream runMasterList::openOutReportOne() {
	ofstream outfile;
	string fileName = "ReportOne.txt";
	outfile.open(fileName.c_str(), std::ios::out);
	if (outfile.is_open()) {
		return outfile;
	}
	else {
		cout << "Error writing to file!" << endl;
	}

}
masterList<Data>& runMasterList::markAbsences(masterList<Data>& List) {
	Node<Data>* pCur = List.getHead();
	string answer;
	string date;
	while (pCur != nullptr) {
		cout << "Is " << pCur->getData().getName() << " Absent? " << endl;
		cout << "YES OR NO" << endl;
		
		cin >> answer;
		if (answer == "YES") {
				date = getDate();
				if (pCur->getData().getStack().peek() != date) {
				pCur->getData().setPushStack(date);
				int var = pCur->getData().getAbs();
				var++;
				pCur->setAbsNode(var);
				
			}
			else {
				cout << "You have already inputted this student as absent for today!" << endl;
			}
		}
		pCur = pCur->getNextPtr();
	}
	return List;
}
string runMasterList::getDate() {
	time_t t = time(0);   // get time now
	struct tm* now = localtime(&t);
	string date;
	date = std::to_string(now->tm_mon + 1) + '-' + std::to_string(now->tm_mday) + '-' + std::to_string(now->tm_year + 1900);
	return date;
}
fstream runMasterList::openMasterList() {
	fstream infile;
	string fileName = "masterList.txt";
	infile.open(fileName.c_str(), std::ios::in);
	if (infile.is_open()) {
		return infile;
	}
	else {
		cout << "Error opening file!" << endl;
	}
}
