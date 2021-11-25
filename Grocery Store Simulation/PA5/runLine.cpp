#define _CRTDBG_MAP_ALLOC
#include "runLine.hpp"
#include <crtdbg.h>
//constructor for 2 new queues and 0 mins
runLine::runLine() {
	NormalLine = new Queue;
	ExpressLine = new Queue;
	 mins = 0;
}

bool runLine::runApp() {

	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//data obj for each line
	Data dataPackNorm;
	Data dataPackEx;
	int incrTen = 10;
	//new arrival time
	int arrivalNorm = getAmtMinsNormal();
	int arrivalEx = getAmtMinsExpress();
	bool success = false;

	int arriveInforNorm = arrivalNorm;
	int arriveInfoEx = arrivalEx;
	//serv time
	int serviceTimeNorm = getAmtMinsNormal();
	int serviceTimeEx = getAmtMinsExpress();

	int totalTimeServEx = serviceTimeEx;
	int totalTimeServNorm = serviceTimeNorm;

	int totalMinsSub = 0;
	//test case, will continue without asking user for how many mins
	if (mins != 1440) {
		 mins = getUserMins();
	}
	
	//set at 1 tho kinda redundant
	int customerNumberEx = 1;
	int customerNumberNorm = 1;
	//-1 for empty list (You cant decrease serv time when empty)
	int tempServEx = -1;
	int tempServNorm = -1;
	//set dataPack for each line
	//(Datapack = new customer)
	dataPackEx.setserviceTime(serviceTimeEx);
	dataPackNorm.setserviceTime(serviceTimeNorm);

	dataPackEx.settotalTime(totalTimeServEx);
	dataPackNorm.settotalTime(totalTimeServNorm);

	dataPackEx.setCustomerNumber(customerNumberEx);
	dataPackNorm.setCustomerNumber(customerNumberNorm);

	dataPackEx.setStartNumber(1);
	dataPackNorm.setStartNumber(1);

	dataPackEx.settotalTime(totalTimeServEx);
	dataPackNorm.settotalTime(totalTimeServNorm);
	//redundant
	if (NormalLine->isempty() && ExpressLine->isempty()) {

		do {

			//once arrival = 0, we go inside, take a look at more conditons
			if (arrivalNorm == 0) {
				//print out info 
				cout << "************************\nNormal cust Arrived\n Customer Number:" << dataPackNorm.getCustomerNumber() << "\nArrival Time: " << arriveInforNorm << "\n************************" << endl;

				//WORK ON PRINTING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
				arrivalNorm = getAmtMinsNormal();
				//get new arrival time for the new customer that is about to get in line
				arriveInforNorm = arrivalNorm;
				serviceTimeNorm = getAmtMinsNormal();
				//if its empty, then we adjust accordingly for the new cust
				if (NormalLine->isempty()) {
					NormalLine->enqueue(dataPackNorm);
					dataPackNorm.setserviceTime(arriveInforNorm);
					dataPackNorm.settotalTime(dataPackNorm.getserviceTime() + NormalLine->getHeadPtr()->getData()->gettotalTime());
					//set numb to 2 bc this is a base case when the first cust enters the queue
					dataPackNorm.setCustomerNumber(2);
					dataPackNorm.setStartNumber(2);
					dataPackNorm.settotalTimePreserve(dataPackNorm.gettotalTime());
				}

				else {
					//else we are going to grab start number first, as it hasnt been updated yet
					dataPackNorm.setStartNumber(dataPackNorm.getCustomerNumber());
					NormalLine->enqueue(dataPackNorm);
					dataPackNorm.setserviceTime(arriveInforNorm);
					//adjust accordingly for the new cust
					dataPackNorm.settotalTime(dataPackNorm.getserviceTime() + NormalLine->getTailPtr()->getData()->gettotalTime());
					dataPackNorm.settotalTimePreserve(dataPackNorm.gettotalTime());
					dataPackNorm.setCustomerNumber(NormalLine->getTailPtr()->getData()->getCustomerNumber() + 1);

				}


			}//when people are done with their serv time, then we dequeue
			if (tempServNorm == 0) {
				//error when leaving
				Data returnData;
				//grab return data bc its useful for printing out the customers info
				returnData = NormalLine->dequeue();
				cout << "************************\nNormal cust Left\n Customer Number:" << returnData.getStartNumber() << "\nTotal Time: " << returnData.gettotalTimePreserve() << "\n************************" << endl;
				//if its not empty
				if (!NormalLine->isempty()) {
					//then we go ahead and change every single person in line and decrement or increment 
					//I decided to restart the count of cust numb everytime because it made me feel more secure
					QueueNode* pCur = NormalLine->getHeadPtr();

					int incr = 0;
					
					while (pCur != nullptr) {
						pCur->getData()->settotalTime(pCur->getData()->gettotalTime() - returnData.getserviceTime());
						pCur->getData()->setCustomerNumber(++incr);
						pCur = pCur->getNextPtr();
					}
					//after we are done updating that info, we go ahead and make a change to cust waiting
					dataPackNorm.settotalTime(dataPackNorm.gettotalTime() - returnData.getserviceTime());
					dataPackNorm.setCustomerNumber(dataPackNorm.getCustomerNumber() - 1);
					//updated the serv time for the next customer in queue
					tempServNorm = NormalLine->getHeadPtr()->getData()->getserviceTime();
				}
				else {
					//if its empty, then we stay the same
					tempServNorm = -1;
					//but we update the waiting cust to one and subtract their service time
					dataPackNorm.setCustomerNumber(1);
					dataPackNorm.settotalTime(dataPackNorm.gettotalTime() - returnData.getserviceTime());
				}
			}//same idea here
			if (arrivalEx == 0) {
				cout << "************************\nExpress cust Arrived\n Customer Number:" << dataPackEx.getCustomerNumber() << "\nArrival Time: " << arriveInfoEx << "\n************************" << endl;
				arrivalEx = getAmtMinsExpress();
				arriveInfoEx = arrivalEx;
				serviceTimeEx = getAmtMinsExpress();
				if (ExpressLine->isempty()) {
					ExpressLine->enqueue(dataPackEx);
					dataPackEx.setserviceTime(arriveInfoEx);
					dataPackEx.settotalTime(dataPackEx.getserviceTime() + ExpressLine->getHeadPtr()->getData()->gettotalTime());
					dataPackEx.setCustomerNumber(2);
					dataPackEx.setStartNumber(2);
					dataPackEx.settotalTimePreserve(dataPackEx.gettotalTime());
				}
				else {
					dataPackEx.setStartNumber(dataPackEx.getCustomerNumber());
					
					ExpressLine->enqueue(dataPackEx);
					dataPackEx.setserviceTime(arriveInfoEx);
					dataPackEx.settotalTime(dataPackEx.getserviceTime() + ExpressLine->getTailPtr()->getData()->gettotalTime());
					dataPackEx.settotalTimePreserve(dataPackEx.gettotalTime());
					dataPackEx.setCustomerNumber(ExpressLine->getTailPtr()->getData()->getCustomerNumber() + 1);

				}


			}//as well as here
			if (tempServEx == 0) {
				Data returnData;
				returnData = ExpressLine->dequeue();
				cout << "************************\nExpress cust Left\n Customer Number:" << returnData.getStartNumber() << "\nTotal Time: " << returnData.gettotalTimePreserve() << "\n************************" << endl;

				if (!ExpressLine->isempty()) {
					QueueNode* pCur = ExpressLine->getHeadPtr();
				


					while (pCur != nullptr) {
						pCur->getData()->settotalTime(pCur->getData()->gettotalTime() - returnData.getserviceTime());
						pCur->getData()->setCustomerNumber(pCur->getData()->getCustomerNumber() - 1);
						pCur = pCur->getNextPtr();
					}
					dataPackEx.settotalTime(dataPackEx.gettotalTime() - returnData.getserviceTime());
					dataPackEx.setCustomerNumber(dataPackEx.getCustomerNumber() - 1);
					tempServEx = ExpressLine->getHeadPtr()->getData()->getserviceTime();
				}
				else {
					
					tempServEx = -1;
					dataPackEx.setCustomerNumber(1);
					dataPackEx.settotalTime(dataPackEx.gettotalTime() - returnData.getserviceTime());
				}
			}
			//if its not empty and we havent updated the -1 for serv, then we update
			if (!ExpressLine->isempty() && tempServEx == -1) {
				tempServEx = ExpressLine->getHeadPtr()->getData()->getserviceTime();

			}

			if (!NormalLine->isempty() && tempServNorm == -1) {
				tempServNorm = NormalLine->getHeadPtr()->getData()->getserviceTime();
			}
			//decrementing vars
			--arrivalNorm;
			--arrivalEx;

			if (tempServEx != -1) {//if neg one, dont touch
				--tempServEx;
			}

			if (tempServNorm != -1) {
				--tempServNorm;
			}

		

		
			
			totalMinsSub++;//add the global var for funct
			if (totalMinsSub == 1440) {//if its 1440, then we change the whole cust, and make them the first.
				int countNorm = 0;
				int countEx = 0;

				countNorm = NormalLine->sizeOf(*NormalLine);
				countEx = ExpressLine->sizeOf(*ExpressLine);
				//first count then dequeue
				for (int i = 1; i <= countNorm; i++) {
					NormalLine->dequeue();
				}

				for (int i = 1; i <= countEx; i++) {
					ExpressLine->dequeue();
				}
				 arrivalNorm = getAmtMinsNormal();
				 arrivalEx = getAmtMinsExpress();
				 arriveInforNorm = arrivalNorm;
				 arriveInfoEx = arrivalEx;

				 serviceTimeNorm = getAmtMinsNormal();
				 serviceTimeEx = getAmtMinsExpress();
				totalTimeServEx = serviceTimeEx;
				totalTimeServNorm = serviceTimeNorm;
				


			

				tempServEx = serviceTimeEx;
				tempServNorm = serviceTimeNorm;



				dataPackEx.setCustomerNumber(1);
				dataPackNorm.setCustomerNumber(1);

				dataPackEx.setStartNumber(1);
				dataPackNorm.setStartNumber(1);
				
				dataPackEx.setserviceTime(serviceTimeEx);
				dataPackNorm.setserviceTime(serviceTimeNorm);

				dataPackEx.settotalTime(totalTimeServEx);
				dataPackNorm.settotalTime(totalTimeServNorm);

				dataPackEx.settotalTimePreserve(dataPackEx.gettotalTime());
				dataPackNorm.settotalTimePreserve(dataPackNorm.gettotalTime());
				//enqueue the first customer, as stated in the rubric
				NormalLine->enqueue(dataPackNorm);
				ExpressLine->enqueue(dataPackEx);





				arrivalNorm = getAmtMinsNormal();
				arrivalEx = getAmtMinsExpress();
				arriveInforNorm = arrivalNorm;
				arriveInfoEx = arrivalEx;

				serviceTimeNorm = getAmtMinsNormal();
				serviceTimeEx = getAmtMinsExpress();
				//make new cust for waiting customer
				dataPackEx.setCustomerNumber(2);
				dataPackNorm.setCustomerNumber(2);

				dataPackEx.setStartNumber(2);
				dataPackNorm.setStartNumber(2);

				dataPackEx.setserviceTime(serviceTimeEx);
				dataPackNorm.setserviceTime(serviceTimeNorm);

				dataPackEx.settotalTime(dataPackEx.getserviceTime() + ExpressLine->getTailPtr()->getData()->gettotalTime());
				dataPackNorm.settotalTime(dataPackNorm.getserviceTime() + NormalLine->getTailPtr()->getData()->gettotalTime());

				dataPackEx.settotalTimePreserve(dataPackEx.gettotalTime());
				dataPackNorm.settotalTimePreserve(dataPackNorm.gettotalTime());



				//continue until time is done

				cout << "**********RESET*******************" << endl;

			}
			if (totalMinsSub == incrTen) {//this is for printing every 10 mins.
				cout << "*****Express Lane*****" << endl << endl;
				ExpressLine->printQueue(*ExpressLine);
				cout << "*****Normal Lane*****" << endl;
				NormalLine->printQueue(*NormalLine);
				incrTen += 10;//incr comp var
			}
			//this is mainly for testing purposes, doesnt stop the program bc i didnt return 
			if (totalMinsSub == 1440 && NormalLine->sizeOf(*NormalLine) == 1 && ExpressLine->sizeOf(*ExpressLine) == 1) {
				success = true;
			}
			//global comparison
		} while (totalMinsSub != mins);
		
		
	}//for testing! mainly...
	return success;
}
int runLine::getAmtMinsExpress(void) {
	//gets the rand num.. btw thanks for the help!
	int lower = 1;
	int upper = 5;
	int time = 0;
	time = (rand() % (upper - lower + 1)) + lower;
	return time;
}

int runLine::getAmtMinsNormal(void) {
	//gets the rand num.. btw thanks for the help!
	int lower = 3;
	int upper = 8;
	int time = 0;
	time = (rand() % (upper - lower + 1)) + lower;
	return time;
}
runLine::~runLine() {
	//destructor for the two queues, idk if its right but i tried
	delete NormalLine;
	delete ExpressLine;
}


int runLine::getUserMins() {
	//first thing the program asks of the user
	cout << "How many minutes would you like to run the simulation?" << endl;
	 mins = 0;
	cin >> mins;
	return mins;//this is a member var
}
//setter for mins
void runLine::setUserMinsTest(int minsTest) {
	mins = minsTest;
}