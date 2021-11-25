#include "runLine.hpp"
#include "enqueueTestOne.hpp"
#include "enqueueTestTwo.hpp"
#include "dequeueTestOne.hpp"
#include "dequeueTestTwo.hpp"
#include "TestCase24Hrs.hpp"
//main obvi
int main(void) {
	//test cases disabled
	/*runTestOne();
	runTestTwo();
	runTestOneDe();
	runTestTwoDe();
	runTestMode();*/
	//starts off program
	srand(time(NULL));
	runLine Test;
	Test.runApp();

	
}
	