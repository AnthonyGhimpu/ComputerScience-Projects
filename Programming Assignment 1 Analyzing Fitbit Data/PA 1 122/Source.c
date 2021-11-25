#include "header.h"
/*************************************************************
 * Function: readParseClenseData()                                     *
 * Date Created:  9/6/21                                           *
 * Date Last Modified: 9/9/21                                       *
 * Description: This function parses the data accordingly based on the ',' delimitter, as well as fills in gaps in the data based on patterns seen throughout the data set. It also gets rid of any dupes                                              *
 * Input parameters: none                                         *
 * Returns: 0                                                  *
 * Preconditions: Data is not suitible for analysis                                            *
 * Postconditions: all nodes need to fit accordingly within 1440 nodes                                           *
 *************************************************************/
int readParseClenseData() {
	//open files
	FILE* infile = fopen("FitbitData.csv", "r");
	FILE* outfile = fopen("Results.csv", "w");
	//initialize struct array
	FitBitData fitbit[1440];

	int lineNumber = 0;
	char line[1000] = "";
	char timeCheck[10] = "";
	int heartRateNew;
	char heartLine[5];
	char tempArray[4];
	int lengthTimeCheck = 0;
	char timeCheckRecent[10] = "";
	

	double valueCalories = 0;
	double valueDistance = 0;
	int valueFloors = 0;
	int valueSteps = 0;
	double valueHeartrate = 0;
	char sleepRangeBegin[25];
	char sleepRangeEnd[25];
	int MaxSteps = 0;
	//file check
	if (infile != NULL && outfile != NULL) {
		printf("FILEs HAVE BEEN OPENED SUCCESSFULLY\n");
		
		//till the end of the file
		while (!feof(infile)) {
			lengthTimeCheck = 0;
			//need to refresh the buffer, as some length of lines are longer than others
			for (int i = 0; i <= 100; i++) {
				line[i] = '\0';
			}
			//gets the first line in the data sheet
			fgets(line, 1000, infile);
			//copy time first to make some adjustments based on length and to check for dupes
			strcpy(timeCheck, fitbit[lineNumber - 1].minute);
			//need to compare lengths, as it could cause fitting problems when embedding times in the struct as well as buffer
			while (timeCheck[lengthTimeCheck] != '\0') {
				lengthTimeCheck++;
			}
			//if hour is only one digit...
			if (lengthTimeCheck <= 7) {
				//look at formatting. checking for dupes
				if ((line[1] != '2') || (timeCheck[2] == line[8]) && (timeCheck[3] == line[9])) {
					//get next line in data
					fgets(line, 1000, infile);
				}
			}//times can also have two digit hours, so we need to adjust accordingly
			else if((timeCheck[3] == line[9]) && (timeCheck[4] == line[10]) ){
				fgets(line, 1000, infile);
			}//update length of time
			int lengthOfLine = 0;
			int lengthOfLineEdit = 0;
			for (int i = 0; i <= 100; i++) {
				if (line[i] != '\0') {
					lengthOfLine++;
				}
		}//this is checking for which data points are missing, then we move around the nodes in the buffer to make space for new data
			for (int j = 0; j <= 100; j++) {
				if ((line[j] == ',') && (line[j + 1] == ',') && (line[j + 3] ==',')) {
					tempArray[0] = line[j + 2];
					tempArray[1] = line[j + 3];
					tempArray[2] = line[j + 4];
					tempArray[3] = line[j + 5];
					heartRateNew =  (fitbit[lineNumber - 1].heartRate + fitbit[lineNumber - 2].heartRate + 1)/2;
				
					sprintf(heartLine, "%d", heartRateNew);
					strcpy(&line[j + 1], heartLine);
					//heart rates can be 3 digits or 2, so we adjust accordingly
					if (heartRateNew > 100) {
						strcpy(&line[j + 5], tempArray);
						line[j + 4] = ',';
					
						lengthOfLine += 3;
					}
					else {
						strcpy(&line[j + 4], tempArray);
						line[j + 3] = ',';
				
						lengthOfLine += 2;

					}
				}
			}//once the cleaning and missing data are dealt with, we can start parsing
			strcpy(fitbit[lineNumber].patient, strtok(line, ",")); //you could also say  strtok(&line, &line[5]) because it accpets the address at the start of a string
			strcpy(fitbit[lineNumber].minute, strtok(NULL, ",")); //why is it null?
			fitbit[lineNumber].calories = atof(strtok(NULL, ","));
			fitbit[lineNumber].distance = atof(strtok(NULL, ","));
			fitbit[lineNumber].floors = atoi(strtok(NULL, ","));
			fitbit[lineNumber].heartRate = atoi(strtok(NULL, ","));
			fitbit[lineNumber].steps = atoi(strtok(NULL, ","));
			//last thing we need to look for would be the sleep value, since its last, we can make it the last thing we look at. simple conditions
			if ((line[lengthOfLine - 1] == '\n') && (line[lengthOfLine-2] == '\0')) {
				line[lengthOfLine] = '\n';
				line[lengthOfLine-1] = '0';
				fitbit[lineNumber].sleepLevel = atoi(strtok(NULL, "\n"));
			}
			else {
				fitbit[lineNumber].sleepLevel = atoi(strtok(NULL, "\n"));
			}//incr line
			lineNumber++;
		}//now we can do analysis on the data 
		worstSleepRange(fitbit, sleepRangeBegin, sleepRangeEnd);
		
		(double)valueHeartrate += calcHeartRate(fitbit);
		
		valueFloors = calcFloor(fitbit);
		valueSteps = calcSteps(fitbit);
		(double) valueCalories = calcCal(fitbit);
		(double)valueDistance = calcDist(fitbit);
		MaxSteps = maxSteps(fitbit);

		insertOutfile(outfile, fitbit, valueCalories, valueDistance, valueFloors, valueSteps, valueHeartrate, MaxSteps,sleepRangeBegin,sleepRangeEnd);
		
		

	}
	//close files
	fclose(infile);
	fclose(outfile);

	return 0;
}


/*************************************************************
 * Function: insertOutfile(FILE* outfile, FitBitData* fitbit, double valueCalories, double valueDistance, int valueFloors, int valueSteps, int valueHeartrate, int MaxSteps)                                    *
 * Date Created:  9/9/21                                           *
 * Date Last Modified: 9/9/21                                       *
 * Description: This function releases data out to the outfile                                             *
 * Input parameters: (FILE* outfile, FitBitData* fitbit, double valueCalories, double valueDistance, int valueFloors, int valueSteps, int valueHeartrate, int MaxSteps, char* sleepRangeBegin, char *sleepRangeEnd)                                       *
 * Returns: void                                                 *
 * Preconditions: file is aready open                                           *
 * Postconditions: all data must be posted to result.csv                                          *
 *************************************************************/
 insertOutfile(FILE* outfile, FitBitData* fitbit, double valueCalories, double valueDistance, int valueFloors, int valueSteps, double valueHeartrate, int MaxSteps, char* sleepRangeBegin, char *sleepRangeEnd) {

	fprintf(outfile, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
	fprintf(outfile, "%f,%f,%d,%d,%f,%d,%s:%s\n", valueCalories, valueDistance, valueFloors, valueSteps, valueHeartrate,MaxSteps, sleepRangeBegin, sleepRangeEnd);
	printf("Target: 12cx7\nPatient,minute,calories,distance,floors,heart,steps,sleep_level\n");
	for (int k = 0; k <= 1439; k++) {
		fprintf(outfile, "%s,%s,%f,%f,%d,%d,%d,%d\n", fitbit[k].patient, fitbit[k].minute, fitbit[k].calories, fitbit[k].distance, fitbit[k].floors, fitbit[k].steps, fitbit[k].heartRate, fitbit[k].sleepLevel);

		printf("%s,%s,%f,%f,%d,%d,%d,%d\n", fitbit[k].patient, fitbit[k].minute, fitbit[k].calories, fitbit[k].distance, fitbit[k].floors, fitbit[k].steps, fitbit[k].heartRate, fitbit[k].sleepLevel);
	}

}
 /*************************************************************
 * Function: worstSleepRange(FitBitData* fitbit, char* sleepRangeBegin, char* sleepRangeEnd)                                 *
 * Date Created:  9/9/21                                           *
 * Date Last Modified: 9/10/21                                       *
 * Description: This function obtains the string values for the beginning of worst sleep all the way to the end                                          *
 * Input parameters: (FitBitData* fitbit, char* sleepRangeBegin, char* sleepRangeEnd)                                     *
 * Returns: void                                                 *
 * Preconditions: sequence must be in order, worst sleep is considered to be levels greater than 1                                           *
 * Postconditions: must copy string                                        *
 *************************************************************/
 void worstSleepRange(FitBitData* fitbit, char* sleepRangeBegin, char* sleepRangeEnd) {
	 int grandTotal[25];
	 int k = 0;
	 int sequence = 0;
	 int startSegment = 0;
	 int endSegment = 0;
	 int compNum = 0;
	 int SumCur = 0;
	//looking through the whole array
	 for (int i = 0; i < 1440; i++) {
		 if (fitbit[i].sleepLevel > 1) {
			 //whenever a number is greater than 1, we store the positions in another array
			 grandTotal[k] = i;
			 k++;
		 }
	 }
	 //looking through the whole array and checking whether the next node is the position + 1 so its in order
	 for (int i = 0; i <= 24; i++) {
		 if (grandTotal[i] + 1 == grandTotal[i + 1]) {
			 //we are obtaining the sequences that have the highest amount of sleepLevel
			 SumCur += fitbit[grandTotal[i]].sleepLevel;
			 sequence++;
		 }
			 //comparing numbers and seeing which sequence is the highest, while saving the positions where the start and end is
			 if (SumCur > compNum) {
				 startSegment = grandTotal[i-1];
				 endSegment = grandTotal[i + sequence];
				 compNum = SumCur;
			 }//restarting sum when if statement fails for further comparisons
			 SumCur = 0;

			
		 
	 }
	 //copy over string times
	 strncpy(sleepRangeBegin, fitbit[startSegment].minute, 10);
	 strncpy(sleepRangeEnd, fitbit[endSegment].minute, 10);
 }

 /*************************************************************
* Function: maxSteps(FitBitData* fitbit)                                *
* Date Created:  9/9/21                                           *
* Date Last Modified: 9/10/21                                       *
* Description: This function obtains the int value for max steps                                          *
* Input parameters: (FitBitData* fitbit)                                    *
* Returns: int                                                 *
* Preconditions: must have access to struct array                                           *
* Postconditions: return max                                     *
*************************************************************/
 int maxSteps(FitBitData* fitbit) {
	 int max = 0;
	 for (int i = 0; i < 1440; i++) {
		 if (max < fitbit[i].steps) {
			 max = fitbit[i].steps;
		 }
	 }
	 return max;
 }
 /*************************************************************
* Function: calcCal(FitBitData* fitbit)                                *
* Date Created:  9/9/21                                           *
* Date Last Modified: 9/10/21                                       *
* Description: This function obtains the total double value for calories                                        *
* Input parameters: (FitBitData* fitbit)                                    *
* Returns: int                                                 *
* Preconditions: must have access to struct array                                           *
* Postconditions: return calories                                     *
*************************************************************/
double calcCal(FitBitData* fitbit) {
	 double value = 0.0;
	 for (int v = 0; v <= 1439; v++) {
		 value += fitbit[v].calories;
	 }
	 return value;
 }
/*************************************************************
* Function: calcDist(FitBitData* fitbit)                                *
* Date Created:  9/9/21                                           *
* Date Last Modified: 9/10/21                                       *
* Description: This function obtains the total double value for distance                                        *
* Input parameters: (FitBitData* fitbit)                                    *
* Returns: double                                                 *
* Preconditions: must have access to struct array                                           *
* Postconditions:                                      *
*************************************************************/
 double calcDist(FitBitData* fitbit) {
	  double value = 0.0;
	 for (int d = 0; d <= 1439; d++) {
		 value += fitbit[d].distance;
	 }
	 return value;
 }
 /*************************************************************
 * Function: calcDist(FitBitData* fitbit)                                *
 * Date Created:  9/9/21                                           *
 * Date Last Modified: 9/10/21                                       *
 * Description: This function obtains the total int value for floors climbed                                        *
 * Input parameters: (FitBitData* fitbit)                                    *
 * Returns: int                                                 *
 * Preconditions: must have access to struct array                                           *
 * Postconditions:                                      *
 *************************************************************/
 int calcFloor(FitBitData* fitbit) {
	 int value = 0;
	 for (int c = 0; c < 1440; c++) {
		 value += fitbit[c].floors;
	 }
	 return value;
 }
 /*************************************************************
* Function: calcSteps(FitBitData* fitbit)                                *
* Date Created:  9/9/21                                           *
* Date Last Modified: 9/10/21                                       *
* Description: This function obtains the total int value for steps taken                                     *
* Input parameters: (FitBitData* fitbit)                                    *
* Returns: int                                                 *
* Preconditions: must have access to struct array                                           *
* Postconditions:                                      *
*************************************************************/
 int calcSteps(FitBitData* fitbit) {
	 int value = 0;
	 for (int c = 0; c < 1440; c++) {
		 value += fitbit[c].steps;
	 }
	 return value;
 }
 /*************************************************************
* Function: calcSteps(FitBitData* fitbit)                                *
* Date Created:  9/9/21                                           *
* Date Last Modified: 9/10/21                                       *
* Description: This function obtains the total double value for steps taken                                     *
* Input parameters: (FitBitData* fitbit)                                    *
* Returns: double                                                 *
* Preconditions: must have access to struct array                                           *
* Postconditions:                                      *
*************************************************************/
double calcHeartRate(FitBitData* fitbit) {
	 double value = 0;
	 for (int c = 0; c < 1440; c++) {
		 value += fitbit[c].heartRate;
	 }
	 return value/1440;
 }