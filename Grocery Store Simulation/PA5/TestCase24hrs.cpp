#include "TestCase24Hrs.hpp"
void runTestMode() {
	TestCase24Hrs T;
	T.runTest();
}
void TestCase24Hrs::runTest() {
	runLine r;
	bool success = false;
	r.setUserMinsTest(1440);
	success = r.runApp();
	

	if (success == false) {
		cout << "There was an error with the amount of nodes at the end of the day!" << endl;
		cout << "Or program did not finish!" << endl;
	}
	else {
		cout << "Program finished with 1 customer for both nodes!" << endl;
	}
}