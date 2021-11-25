/*******************************************************************************************

* Programmer: Anthony Ghimpu                                                                       *

* Class: CptS 122, Fall 2021; Lab Section 9                                            *

* Programming Assignment: PA 2 and 3                                        *

* Date: September 15, 2020                                                                           *

* Description: This program mimics a playlist program which utilizes a DOUBLY LINKED LIST data structure     *

*******************************************************************************************/

#include "header.h"
//main
int main(int argc, char* argv[]) {
	// testInsertFunction();
//	 testDeleteFunct();

	//initialize the list
	List PlayList = { NULL };
	//The head of the list should point to NULL as there is nothing in the list yet
	initList(&PlayList);
	//This Record type struct acts as a buffer for new information only when loading information in the list
	Record newDataLine = { " " };
	int option = 0;
	int loadCheck = 0;
	//this the main menu, which uses a do-while and a switch statement. Continues unless you press option 11.
	do {
		printf("(1) load \n (2) store\n (3) display \n (4) insert \n (5) delete \n (6) edit \n (7) sort \n (8) rate\n (9) play \n (10) shuffle \n (11) exit\n");
		scanf("%d", &option);
		switch (option) {
			//each key calls each required function
		case 1:
			//passing in list as well as buffer
		load(&PlayList, &newDataLine);
			break;
		case 2:
			//after the playlist is loaded, we can continue with other options
			store(&PlayList);
			break;
		case 3:
			display(&PlayList);
			break;
		case 4:
			insert(&PlayList);
			break;
		case 5:
			deleteNode(&PlayList);
			break;
		case 6:
			edit(&PlayList);
			break;
		case 8:
			rate(&PlayList);
			break;
		case 7:
			sortMenu(&PlayList);
			break;
		case 9:
			play(&PlayList);
			break;
		case 10:
			shuffle(&PlayList);
			break;
		case 11:
			exitFunc(&PlayList);
			break;
		}
	} while (option != 11);
	return 0;
}

