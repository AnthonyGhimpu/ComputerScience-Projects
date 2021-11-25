#include "testDelete.h"
void testDeleteFunct(void) {
	List PlayList = { NULL };
	initList(&PlayList);// = { "Perry, Katy","Witness","Chained to the Rhythm","pop",436,3,5 };

	insert(&PlayList);
	int success = 0;
	success = deleteNode(&PlayList);

	if (success == 0) {
		printf("Success failed\n");

	}
	else {
		printf("Success matched result\n");
	}

if (PlayList.pHead == NULL) {
		printf("head is initialized to NULL correctly\n");
	}
	else {
		printf("Node is still there!\n");
	}
}
