#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum sleep {
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
}Sleep;
typedef struct fitbit {
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
}FitBitData;

readParseClenseData();
double calcCal(FitBitData* fitbit);
double calcDist(FitBitData* fitbit);
int calcFloor(FitBitData* fitbit);
int calcSteps(FitBitData* fitbit);
double calcHeartRate(FitBitData* fitbit);
int maxSteps(FitBitData* fitbit);
void worstSleepRange(FitBitData* fitbit, char* sleepRangeBegin, char* sleepRangeEnd);
insertOutfile(FILE* outfile, FitBitData* fitbit, double valueCalories, double valueDistance, int valueFloors, int valueSteps, double valueHeartrate, int MaxSteps, char* sleepRangeBegin, char* sleepRangeEnd);
#endif