#include "testInsert.h"
void testInsertFunction(void) {
	List PlayList = { NULL };
	initList(&PlayList);
	int success = 0;
	success = insert(&PlayList);
	int countNum = count(&PlayList);
	if (success == 0) {
		printf("Success failed\n");

	}
	else {
		printf("Success matched result\n");
	}
	if (&PlayList == NULL) {
		printf("Failed, list is empty\n");
	}
	else {
		printf("Success, playlist has a value\n");
	}if (countNum != 1) {
		printf("number of items are invalid\n");
	}
	else {
		printf("1 node works ig\n");
	}if (PlayList.pHead->song.rating > 5) {
		printf("error in data acceptance, nothing grater than 5\n");
	}
	else {
		printf("Rating is valid!\n");

	}if (PlayList.pHead != NULL) {
		printf("head is initialized correctly\n");
	}
	else {
		printf("Node inserted is not the head node!\n");
	}if (PlayList.pHead->song.numberTimesPlayed < 1) {
		printf("invalid number for # times played!\n");

	}
	else {
		printf("Valid # times played\n");
	}
}