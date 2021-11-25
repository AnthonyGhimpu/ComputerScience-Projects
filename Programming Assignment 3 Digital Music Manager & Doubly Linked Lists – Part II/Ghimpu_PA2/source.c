#include "header.h"
/*************************************************************
 * Function: makeNode(const Record* pNewData)                                   *
 * Date Created:  9/11/21                                           *
 * Date Last Modified: 9/11/21                                       *
 * Description: This function creates a new node via allocating memory with malloc, as well as copys the data from type RECORD into corresponding structs inside of NODE                                           *
 * Input parameters: Record* pNewData                                         *
 * Returns: pMem or new corresponding node                                                  *
 * Preconditions: Data should already be parsed when called                                           *
 * Postconditions: all nodes need to be called back to insertion function                                         *
 *************************************************************/
Node* makeNode(const Record* pNewData) {
	//allocation
	Node* pMem = (Node *) malloc(sizeof(Node));
	// meaning pMem is successfully allocated
	if (pMem != NULL) {
	//	printf("initialized memory for data!\n");
		//pMem->song.albumTitle = pNewData->albumTitle;
		//we copy the information into pMem
		strncpy(pMem->song.albumTitle, pNewData->albumTitle, 50);
		strncpy(pMem->song.artist, pNewData->artist, 50);
		strncpy(pMem->song.genre, pNewData->genre, 50);
		pMem->song.numberTimesPlayed = pNewData->numberTimesPlayed;
		pMem->song.rating = pNewData->rating;
		pMem->song.length.minutes = pNewData->length.minutes;
		pMem->song.length.seconds = pNewData->length.seconds;
		strncpy(pMem->song.songTitle, pNewData->songTitle, 50);
		//pointers for both prev and next should be NULL, as they are floating nodes
		pMem->pNext = NULL;
		pMem->pPrev = NULL;
	}
	return pMem;
 }
/*************************************************************
 * Function: printList(Node* pNode)                                   *
 * Date Created:  9/11/21                                           *
 * Date Last Modified: 9/11/21                                       *
 * Description: This function utilizes recursion in order to print out the entire list                               *
 * Input parameters: Node* pNode                                        *
 * Returns: void                                              *
 * Preconditions:                                         *
 * Postconditions: all nodes must be printed                                     *
 *************************************************************/

void printList(Node* pNode) {
	//condition where there is something in the list
	if (pNode != NULL) {
		//print then call function back until pNext is NULL
		printf("--> %s, %s, %s, %s, %d:%d, %d, %d\n", pNode->song.artist, pNode->song.albumTitle, pNode->song.songTitle, pNode->song.genre, pNode->song.length.minutes, pNode->song.length.seconds, pNode->song.numberTimesPlayed, pNode->song.rating);
		printList(pNode->pNext);
	}
	else {
		printf("-->\n");
	}
}
/*************************************************************
 * Function: sortMenu(List* pList)                                  *
 * Date Created:  9/25/21                                           *
 * Date Last Modified: 9/27/21                                         *
 * Description: This function creates a menu for sorting                           *
 * Input parameters:List* pList                                       *
 * Returns: void                                              *
 * Preconditions: list must not be empty                                        *
 * Postconditions:                                     *
 *************************************************************/
void sortMenu(List* pList) {
	int option = 0;
	if (pList->pHead == NULL)
	{
		printf("Warning! your list is empty!\n");
		return;
	}
		printf("How would you like to sort your list?\n");
	printf("1. Sort by artist (A-Z)?\n2. Sort by album title (A-Z)?\n3. Sort by rating (1-5)\n4.Sort bt amount times played?\n.");
	scanf("%d", &option);
	switch (option) {
	case 1:
		sortByArtist(pList);
		break;
	case 2:
		sortByAlbum(pList);
		break;

	case 3:
		sortByRating(pList);
		break;

	case 4:
		sortByAmtTimesPlayed(pList);
		break;

	}
}
/*************************************************************
 * Function: sortByArtist(List* pList)                                 *
 * Date Created:  9/25/21                                           *
 * Date Last Modified: 9/27/21                                        *
 * Description: This function sorts the list of records based on an attribute                        *
 * Input parameters:List* pList                                       *
 * Returns: void                                              *
 * Preconditions: list must not be empty                                        *
 * Postconditions:                                     *
 *************************************************************/
Node* sortByArtist(List* pList) {
	//count to make sure there are enough nodes in the list
	int countNum = count(pList);
	Node* pCur = pList->pHead;
	//two temp variables for reference on where to replace in front and behind pCur. 
	Node* tempNode;
	Node *tempNodeTwo;
	
	int check = 0;
	


	if (pCur != NULL) {
		if (countNum == 0 || countNum == 1) {
			return;
		}

		int check = 0;
		while (check == 0) {
			//1 represents that the list is sorted based on where the scope exits from the while loop below
			check = 1;
			
			pCur = pList->pHead;
			//iterating through the list condition
			while (pCur->pNext != NULL) {
				//compare
				if ((strcmp(pCur->song.artist, pCur->pNext->song.artist) > 0)) {
					//we need to get the temp addresses on both sides of the node because we are going to make changes, but we still need the address of current
					tempNode = pCur->pPrev;
					tempNodeTwo = pCur->pNext;
					//if its not the start of the list..
					if (tempNode != NULL) {
						//if it isnt, we are going to cycle between pointers from the prev to next and link up with the next ptr and move it to the right
						tempNode->pNext = tempNodeTwo;
					}
					else {//if it is at the start, we can scoot the ptr that has the lesser value over to the head ptr and then we continue linking... this is just for the start if it applies
						pList->pHead = tempNodeTwo;
					}
					//link current over one so we can move the ptr needed
					pCur->pNext = tempNodeTwo->pNext;
					//if the one next to temp2 is not null or the last in the list
					if (tempNodeTwo->pNext != NULL) {
						//we can link the node next to temp on the right side over to pCur so we can move
						tempNodeTwo->pNext->pPrev = pCur;
					}
					//moving temp2 infront of pCur
					pCur->pPrev = tempNodeTwo;
					//^^
					tempNodeTwo->pNext = pCur;
					//finish linking
					tempNodeTwo->pPrev = tempNode;
					check = 0;
				}
				else {
					//iterate when no condition has passed above as we continue to update our temp vars
					pCur = pCur->pNext;
				}
			}
			
			
		}
	}
}
	
/*************************************************************
 * Function: sortByAlbum(List* pList)                                 *
 * Date Created:  9/25/21                                           *
 * Date Last Modified: 9/27/21                                        *
 * Description: This function sorts the list of records based on an attribute                        *
 * Input parameters:List* pList                                       *
 * Returns: void                                              *
 * Preconditions: list must not be empty                                        *
 * Postconditions:                                     *
 *************************************************************/
Node* sortByAlbum(List* pList) {
	int countNum = count(pList);
	Node* pCur = pList->pHead;
	Node* tempNode;
	Node* tempNodeTwo;

	int check = 0;


	if (pCur != NULL) {
		if (countNum == 0 || countNum == 1) {
			return;
		}

		int check = 0;
		while (check == 0) {
			check = 1;
			pCur = pList->pHead;
			while (pCur->pNext != NULL) {
				if ((strcmp(pCur->song.albumTitle, pCur->pNext->song.albumTitle) > 0)) {
					tempNode = pCur->pPrev;
					tempNodeTwo = pCur->pNext;
					if (tempNode != NULL) {
						tempNode->pNext = tempNodeTwo;
					}
					else {
						pList->pHead = tempNodeTwo;
					}
					pCur->pNext = tempNodeTwo->pNext;
					if (tempNodeTwo->pNext != NULL) {
						tempNodeTwo->pNext->pPrev = pCur;
					}
					pCur->pPrev = tempNodeTwo;
					tempNodeTwo->pNext = pCur;
					tempNodeTwo->pPrev = tempNode;
					check = 0;
				}
				else {
					pCur = pCur->pNext;
				}
			}
			
		}
	}
}
/*************************************************************
 * Function: sortByRating(List* pList)                                *
 * Date Created:  9/25/21                                           *
 * Date Last Modified: 9/27/21                                       *
 * Description: This function sorts the list of records based on an attribute                        *
 * Input parameters:List* pList                                       *
 * Returns: void                                              *
 * Preconditions: list must not be empty                                        *
 * Postconditions:                                     *
 *************************************************************/
Node* sortByRating(List* pList) {
	int countNum = count(pList);
	Node* pCur = pList->pHead;
	Node* tempNode;
	Node* tempNodeTwo;

	int check = 0;


	if (pCur != NULL) {
		if (countNum == 0 || countNum == 1) {
			return;
		}

		int check = 0;
		while (check == 0) {
			check = 1;
			pCur = pList->pHead;
			while (pCur->pNext != NULL) {
				if (pCur->song.rating > pCur->pNext->song.rating) {
					tempNode = pCur->pPrev;
					tempNodeTwo = pCur->pNext;
					if (tempNode != NULL) {
						tempNode->pNext = tempNodeTwo;
					}
					else {
						pList->pHead = tempNodeTwo;
					}
					pCur->pNext = tempNodeTwo->pNext;
					if (tempNodeTwo->pNext != NULL) {
						tempNodeTwo->pNext->pPrev = pCur;
					}
					pCur->pPrev = tempNodeTwo;
					tempNodeTwo->pNext = pCur;
					tempNodeTwo->pPrev = tempNode;
					check = 0;
				}
				else {
					pCur = pCur->pNext;
				}
			}
	
		}
	}
}
/*************************************************************
 * Function: sortByAmtTimesPlayed(List *pList)                                *
 * Date Created:  9/25/21                                           *
 * Date Last Modified: 9/11/21                                       *
 * Description: This function sorts the list of records based on an attribute                        *
 * Input parameters:List* pList                                       *
 * Returns: void                                              *
 * Preconditions: list must not be empty                                        *
 * Postconditions:                                     *
 *************************************************************/
Node* sortByAmtTimesPlayed(List *pList) {
	int countNum = count(pList);
	Node* pCur = pList->pHead;
	Node* tempNode;
	Node* tempNodeTwo;

	int check = 0;


	if (pCur != NULL) {
		if (countNum == 0 || countNum == 1) {
			return;
		}

		int check = 0;
		while (check == 0) {
			check = 1;
			pCur = pList->pHead;
			while (pCur->pNext != NULL) {
				if (pCur->song.numberTimesPlayed < pCur->pNext->song.numberTimesPlayed) {
					tempNode = pCur->pPrev;
					tempNodeTwo = pCur->pNext;
					if (tempNode != NULL) {
						tempNode->pNext = tempNodeTwo;
					}
					else {
						pList->pHead = tempNodeTwo;
					}
					pCur->pNext = tempNodeTwo->pNext;
					if (tempNodeTwo->pNext != NULL) {
						tempNodeTwo->pNext->pPrev = pCur;
					}
					pCur->pPrev = tempNodeTwo;
					tempNodeTwo->pNext = pCur;
					tempNodeTwo->pPrev = tempNode;
					check = 0;
				}
				else {
					pCur = pCur->pNext;
				}
			}
		}
	}
}
/*************************************************************
 * Function: insertFront(List* pList, const Record* pNewData)                                  *
 * Date Created:  9/11/21                                           *
 * Date Last Modified: 9/11/21                                       *
 * Description: This function inserts nodes at the front of the lists                              *
 * Input parameters:(List* pList, const Record* pNewData)                                       *
 * Returns: int for success                                              *
 * Preconditions:                                         *
 * Postconditions:                                   *
 *************************************************************/

int insertFront(List* pList, const Record* pNewData) {
	//we make new node
	Node* pMem = makeNode(pNewData);
	int success = 0;
	if (pMem != NULL) {
		success = 1;
		//"Successfully allocated memory"
		if (pList->pHead != NULL) {
			//if there is something in the list, we switch links accodringly
			pMem->pNext = pList->pHead;
			//pPrev is the node in the front of pMem, which means it needs to equal pMem
			pList->pHead->pPrev = pMem;
			
			
		}
		//this is an extra safe measure, as it ensures that pHead points to pMem, but also if there is nothing in the list, it will still work.
		pList->pHead = pMem;
	}
	//printList(pMem);
	return success;
}
/*************************************************************
 * Function: initList(List* pList)                                *
 * Date Created:  9/11/21                                           *
 * Date Last Modified: 9/11/21                                       *
 * Description: This function points head to NULL, as there is nothing in the list. We want to ensure it.                             *
 * Input parameters:(List* pList                                       *
 * Returns: void                                          *
 * Preconditions: there should be nothing in the list                                         *
 * Postconditions:                                   *
 *************************************************************/
void initList(List* pList) {
	pList->pHead = NULL;
}
/*************************************************************
 * Function: Node* load(List* pList, Record* pNewdata)                                *
 * Date Created:  9/11/21                                           *
 * Date Last Modified: 9/13/21                                       *
 * Description: This function parses data and then loads it into buffer, then calls insertatfront function                          *
 * Input parameters:(List* pList, Record* pNewdata)                                       *
 * Returns: the entire linked list                                       *
 * Preconditions:                                        *
 * Postconditions:                                   *
 *************************************************************/
Node* load(List* pList, Record* pNewdata) {
	//opening file
	FILE* infile = fopen("musicPlayList.csv", "r");
	//each token goes into data
	char *data = NULL;

	//buffer for each line in file
	char line[200] = "";
	int lengthTime;
	int position = 0;
	if (infile != NULL) {
	//	printf("File has been successfully opened");
		//till the end of the file...
		while (!feof(infile)) {
			lengthTime = 0;
			//refresh buffer
			for (int i = 0; i <= 100; i++) {
				line[i] = '\0';
			}
			//gets a whole line
			fgets(line, 200, infile);
			//we copy each token into a pNewData to its corresponding field
			data = strtok(line, ",");
			strcpy(pNewdata->artist, data);
			//if the artist has a first and last name we want both their names to be included in the field artist, so we use strcat.
			if (line[0] == '\"') {
				data = strtok(NULL, ",");
			
				strcat(pNewdata->artist, ",");
				strcat(pNewdata->artist, data);
			}
			//data overwrites each time we equate it to a token, and even if it has overlapping character, all strings end with a null char.
			data = strtok(NULL, ",");
			
			strcpy(pNewdata->albumTitle, data);
			data = strtok(NULL, ",");
			strcpy(pNewdata->songTitle, data);
			data = strtok(NULL, ",");
			strcpy(pNewdata->genre, data);
			data = strtok(NULL, ":");
			pNewdata->length.minutes = atoi(data);
			data = strtok(NULL, ",");
			pNewdata->length.seconds = atoi(data);
			
			data = strtok(NULL, ",");
			pNewdata->numberTimesPlayed= atoi(data);
			data = strtok(NULL, ",");
			pNewdata->rating = atoi(data);
			data = strtok(NULL, "\n");
			//once we have all the data, we can make this data into a node and insert it at the front.
			insertFront(pList, pNewdata);
		}
	
	}
	return pList;
	//close file
	fclose(infile);
}
/*************************************************************
 * Function: void store(List *pList)                                *
 * Date Created:  9/11/21                                           *
 * Date Last Modified: 9/13/21                                       *
 * Description: This function stores data into the file musicPlayList.csv and overwrites the info                         *
 * Input parameters: List *pList)                                      *
 * Returns: void                                     *
 * Preconditions:                                        *
 * Postconditions:                                   *
 *************************************************************/
void store(List *pList) {
	//open as outfile
	FILE* outfile = fopen("musicPlayList.csv", "w");
	//start of list
	Node* pMem = pList->pHead;
	//we increment through the list until we reach NULL and print out the information that was edited in the list (or not edited)
	while (pMem != NULL){
		//keep the same formatting as .csv
	fprintf(outfile, "%s,", pMem->song.artist);
	fprintf(outfile, "%s,", pMem->song.albumTitle);
	fprintf(outfile, "%s,", pMem->song.songTitle);
	fprintf(outfile, "%s,", pMem->song.genre);
	fprintf(outfile, "%d:%d,", pMem->song.length.minutes, pMem->song.length.seconds);
	fprintf(outfile, "%d,", pMem->song.numberTimesPlayed);
	//little spacing issue, when the list ends, we dont want a space to pop up at the end of the file, as it could cause errors when loading data again, so we need to differentiate
	if (pMem->pNext == NULL) {
		fprintf(outfile, "%d", pMem->song.rating);
		break;
	}
	// \n
	fprintf(outfile, "%d\n", pMem->song.rating);
	pMem = pMem->pNext;
		}

}
/*************************************************************
 * Function: void display(List* pList)                              *
 * Date Created:  9/11/21                                           *
 * Date Last Modified: 9/13/21                                       *
 * Description: This function displays  data to the screen                        *
 * Input parameters: List *pList)                                      *
 * Returns: void                                     *
 * Preconditions:                                        *
 * Postconditions:                                   *
 *************************************************************/
void display(List* pList) {
	//start at head
	 Node* pCur = pList->pHead;
	int option = 0;
	char artist[100];
	char temp[100];
	(system("cls"));
	printf("(1) Print all records \n (2) Print all records that match an artist\n");
	scanf("%d", &option);

	if (option == 1) {
		//just calling printlist function
		printList(pList->pHead);
	}
	else {
		
		(system("cls"));
		printf("Which artist?\n");
		printf("if artist has a first and last name, please format \"Last, First\" (include quotations)\n");
		//pauses and gets string. We could use scanf but the space for some artists may cause issues
		while (getchar() != '\n');
		gets(artist);
		//we look for corresponding artists
		while (pCur != NULL) {
			if (strcmp(pCur->song.artist, artist) == 0) {
				printf("--> %s, %s, %s, %s, %d:%d, %d, %d\n\n", pCur->song.artist, pCur->song.albumTitle, pCur->song.songTitle, pCur->song.genre, pCur->song.length.minutes, pCur->song.length.seconds, pCur->song.numberTimesPlayed, pCur->song.rating);
			}
			//incr through
				pCur = pCur->pNext;
			
		}
	
		
		}
	printf("*****PRESS ENTER TO RETURN TO MENU*****\n");
	while (getchar() != '\n');
	//(system("cls"));
}
/*************************************************************
 * Function: void edit(List* pList)                              *
 * Date Created:  9/11/21                                           *
 * Date Last Modified: 9/13/21                                       *
 * Description: This function enables editing in place                     *
 * Input parameters: List *pList)                                      *
 * Returns: void                                     *
 * Preconditions: list must not be empty                                        *
 * Postconditions:                                   *
 *************************************************************/
void edit(List* pList) {
	Node* pCur = pList->pHead;

	char artist[100];
	char record[100];
	int i = 1;
	int option = 0;
	(system("cls"));
	//get string
	printf("Which artist would you like to edit?\n");
	printf("if artist has a first and last name, please format \"Last, First\" (include quotations)\n");
	while (getchar() != '\n');
	gets(artist);
	//same operation in display
	while (pCur != NULL) {
		if (strcmp(pCur->song.artist, artist) == 0) {
			printf("(%d) %s, %s, %s, %s, %d:%d, %d, %d\n\n", i, pCur->song.artist, pCur->song.albumTitle, pCur->song.songTitle, pCur->song.genre, pCur->song.length.minutes, pCur->song.length.seconds, pCur->song.numberTimesPlayed, pCur->song.rating);
			i++;

		}

		pCur = pCur->pNext;

	}
	pCur = pList->pHead;
	

	printf("Which SONG would you like to edit?\n");
	printf("if song is uppercase, please include.\n");
	//asks for song from artist
	gets(record);
	
	//we iterate through the list and ask which option the user would like to edit with the use of switch statements
	while (pCur != NULL) {
		if (strcmp(pCur->song.songTitle, record) == 0) {
			int optionTwo = 0;
			printf("Which part of the Record would you like to edit?\n");
			printf("(1) artist \n (2) albumTitle\n (3) songTitle \n (4) genre \n (5) length-Minutes \n (6) length-Seconds \n (7) numberTimesPlayed \n (8) rating\n (9) Back to main menu\n");
			scanf("%d", &optionTwo);
			do {
				switch (optionTwo) {
					//each case calls a function
				case 1:
					editArtist(pCur);
					printf("Which part of the Record would you like to edit?\n");
					printf("(1) artist \n (2) albumTitle\n (3) songTitle \n (4) genre \n (5) length-Minutes \n (6) length-Seconds \n (7) numberTimesPlayed \n (8) rating\n (9) Back to main menu\n");
					scanf("%d", &optionTwo);
					break;
				case 2:
					editAlbum(pCur);
					optionTwo = 0;
					printf("Which part of the Record would you like to edit?\n");
					printf("(1) artist \n (2) albumTitle\n (3) songTitle \n (4) genre \n (5) length-Minutes \n (6) length-Seconds \n (7) numberTimesPlayed \n (8) rating\n (9) Back to main menu\n");
					scanf("%d", &optionTwo);
					break;
				case 3:
					editsongTitle(pCur);
					optionTwo = 0;
					printf("Which part of the Record would you like to edit?\n");
					printf("(1) artist \n (2) albumTitle\n (3) songTitle \n (4) genre \n (5) length-Minutes \n (6) length-Seconds \n (7) numberTimesPlayed \n (8) rating\n (9) Back to main menu\n");
					scanf("%d", &optionTwo);
					break;
				case 4:
					editGenre(pCur);
					optionTwo = 0;
					printf("Which part of the Record would you like to edit?\n");
					printf("(1) artist \n (2) albumTitle\n (3) songTitle \n (4) genre \n (5) length-Minutes \n (6) length-Seconds \n (7) numberTimesPlayed \n (8) rating\n (9) Back to main menu\n");
					scanf("%d", &optionTwo);
					break;
				case 5:
					editMinutes(pCur);
					optionTwo = 0;
					printf("Which part of the Record would you like to edit?\n");
					printf("(1) artist \n (2) albumTitle\n (3) songTitle \n (4) genre \n (5) length-Minutes \n (6) length-Seconds \n (7) numberTimesPlayed \n (8) rating\n (9) Back to main menu\n");
					scanf("%d", &optionTwo);
					break;
				case 6:
					editSeconds(pCur);
					optionTwo = 0;
					printf("Which part of the Record would you like to edit?\n");
					printf("(1) artist \n (2) albumTitle\n (3) songTitle \n (4) genre \n (5) length-Minutes \n (6) length-Seconds \n (7) numberTimesPlayed \n (8) rating\n (9) Back to main menu\n");
					scanf("%d", &optionTwo);
					break;
				case 7:
					editTimesPlayed(pCur);
					optionTwo = 0;
					printf("Which part of the Record would you like to edit?\n");
					printf("(1) artist \n (2) albumTitle\n (3) songTitle \n (4) genre \n (5) length-Minutes \n (6) length-Seconds \n (7) numberTimesPlayed \n (8) rating\n (9) Back to main menu\n");
					scanf("%d", &optionTwo);
					break;
				case 8:
					editRating(pCur);
					optionTwo = 0;
					printf("Which part of the Record would you like to edit?\n");
					printf("(1) artist \n (2) albumTitle\n (3) songTitle \n (4) genre \n (5) length-Minutes \n (6) length-Seconds \n (7) numberTimesPlayed \n (8) rating\n (9) Back to main menu\n");
					scanf("%d", &optionTwo);
					break;
				case 9:
					break;
				}

			} while (optionTwo != 9);
			pCur = pCur->pNext;


		}
		pCur = pCur->pNext;
	}
}

/*************************************************************
 * Function: int play(List* pList)                          *
 * Date Created:  9/11/21                                           *
 * Date Last Modified: 9/13/21                                       *
 * Description: This function enables playing each song and shows info                    *
 * Input parameters: List *pList)                                      *
 * Returns: void                                     *
 * Preconditions: list must not be empty                                        *
 * Postconditions:                                   *
 *************************************************************/
int play(List* pList) {
	//we set up both pPrev as well as pCur so we can choose the song we want and continue from there
	Node* pCur = pList->pHead;
	Node* pPrev = pCur->pPrev;
	(system("cls"));
	
	char song[100];
	printList(pList->pHead);
	printf("Which song would you like to start playing?\n");
	while (getchar() != '\n');
	gets(song);
	(system("cls"));
	while (pCur != NULL) {
		//if its the first song in the list
		if (strcmp(pCur->song.songTitle, song) == 0 && pPrev == NULL) {

			printf("\tArtist:%s\n \talbumTitle: %s\n \tsongTitle: %s\n \tgenre: %s\n \tSongLength: %d:%d\n \trating: %d\n\n", pCur->song.artist, pCur->song.albumTitle, pCur->song.songTitle, pCur->song.genre, pCur->song.length.minutes, pCur->song.length.seconds, pCur->song.numberTimesPlayed, pCur->song.rating);
			system("pause");
			(system("cls"));
			pPrev = pCur;
			pCur = pCur->pNext;
			
			break;
		}//if its not the first song...
		else if (strcmp(pCur->song.songTitle, song) == 0) {

			printf("\tArtist:%s\n \talbumTitle: %s\n \tsongTitle: %s\n \tgenre: %s\n \tSongLength: %d:%d\n \trating: %d\n\n", pCur->song.artist, pCur->song.albumTitle, pCur->song.songTitle, pCur->song.genre, pCur->song.length.minutes, pCur->song.length.seconds, pCur->song.numberTimesPlayed, pCur->song.rating);
			system("pause");
			(system("cls"));
			break;
		}
		pPrev = pCur;
		pCur = pCur->pNext;
		
	}//we need to further the incr, as it breaks in a different scope
	pPrev = pCur;
	pCur = pCur->pNext;
	//print the rest of the playList
	while (pCur != NULL) {
		
		printf("\tArtist:%s\n \talbumTitle: %s\n \tsongTitle: %s\n \tgenre: %s\n \tSongLength: %d:%d\n \trating: %d\n\n", pCur->song.artist, pCur->song.albumTitle, pCur->song.songTitle, pCur->song.genre, pCur->song.length.minutes, pCur->song.length.seconds, pCur->song.numberTimesPlayed, pCur->song.rating);
		pPrev = pCur;
		pCur = pCur->pNext;
		system("pause");
		(system("cls"));
	}
	(system("cls"));
	printf("End of PlayList!\n");
	return 1;
}
/*************************************************************
 * Function: Node* rate(List* pList)                         *
 * Date Created:  9/11/21                                           *
 * Date Last Modified: 9/13/21                                       *
 * Description: This function edits the rating of a record                  *
 * Input parameters: List *pList)                                      *
 * Returns: Node        (edits node)                             *
 * Preconditions: list must not be empty                                        *
 * Postconditions:                                   *
 *************************************************************/
Node* rate(List* pList) {
	Node* pCur = pList->pHead;
	char artist[100];
	char record[100];
	int rating = 0;
	int i = 1;
	int option = 0;
	(system("cls"));
	//gets artist name
	printf("Which artist would you like to edit in terms of rating?\n");
	printf("if artist has a first and last name, please format \"Last, First\" (include quotations)\n");
	while (getchar() != '\n');
	gets(artist);
	//prints artist
	while (pCur != NULL) {
		if (strcmp(pCur->song.artist, artist) == 0) {
			printf("(%d) %s, %s, %s, %s, %d:%d, %d, %d\n\n", i, pCur->song.artist, pCur->song.albumTitle, pCur->song.songTitle, pCur->song.genre, pCur->song.length.minutes, pCur->song.length.seconds, pCur->song.numberTimesPlayed, pCur->song.rating);
			i++;

		}

		pCur = pCur->pNext;

	}
	pCur = pList->pHead;
	
	//asks for song
	printf("Which SONG would you like to edit in terms of rating?\n");
	gets(record);
	while (pCur != NULL) {
		if (strcmp(pCur->song.songTitle, record) == 0) {
		//call editRating function just like edit function
			editRating(pCur);
			
			
		}
		pCur = pCur->pNext;
	}
	return pCur;
}
/*************************************************************
 * Function: Node* shuffle(List* pList)     *
 * Date Created:  9/20/21                                           *
 * Date Last Modified: 9/11/21                                       *
 * Description: This function shuffles a linked list by randomly choosing positions and putting nodes infront of pHead                       *
 * Input parameters:List* pList                                       *
 * Returns: void                                              *
 * Preconditions: list must not be empty                                        *
 * Postconditions:                                     *
 *************************************************************/
//DISCLAIMER___| I understand that I was supposed to use another method for the shuffle function by not even moving any links around which would have been ten times easier but i noticed last min...
//So because i made it this way, I cant really add a test function (s'more salt on the wound)
//Next time ill be more attentive and actually READ the assignment :/
Node* shuffle(List* pList) {
	int countNum = count(pList);
	if (countNum == 1) {
		return;
	}
	//random seed
	srand(time(0));
	int amtShuffle = 200;
	int incr = 1;
	int position = 1;
	char option = "";
	//assume that plist is not NULL
	//We also need to check for one node
//Need to check for first insertion or last insertion
	if (pList->pHead == NULL) {
		return;
	}
	Node* tempHead = pList->pHead;
	Node* pCur = pList->pHead;

	while (incr != amtShuffle) {
		int randPos = (rand() % (countNum - 1 + 1)) + 1;
		//find position 
		while ((pCur->pNext != NULL) && position != randPos) {
			pCur = pCur->pNext;

			position++;
		}
		//if at the end, use alternate measures
		if (pCur->pNext == NULL) {
			pCur->pPrev->pNext = NULL;
			tempHead->pPrev = pCur;
			pCur->pNext = tempHead;
			pList->pHead = pCur;
			pCur->pPrev = NULL;
			tempHead = pList->pHead;
		}
		else {//else link other ways
			pCur->pPrev->pNext = pCur->pNext;
			pCur->pNext->pPrev = pCur->pPrev;
			pCur->pNext = tempHead;
			tempHead->pPrev = pCur;
			pList->pHead = pCur;
			pCur->pPrev = NULL;
			tempHead = pList->pHead;
		}
		position = 0;
		incr++;
		randPos = 0;
	}
	interatePrint(pList);
	
}
	
/*************************************************************
 * Function: interatePrint(List * pList)     *
 * Date Created:  9/27/21                                           *
 * Date Last Modified: 9/27/21                                       *
 * Description: This function allows the user to iterate through the list forwards and backwards                    *
 * Input parameters:List* pList                                       *
 * Returns: void                                              *
 * Preconditions: list must not be empty                                        *
 * Postconditions:                                     *
 *************************************************************/
void interatePrint(List * pList) {
	Node* pCurP = pList->pHead;
	char option = "";
	while (pCurP != NULL) {
		printf("Press a to go forwards or b to go backwards\n");
		scanf("%c", &option);
		if (option == 'a') {
			if (pCurP->pNext == NULL) {
				printf("You are at the end of your playlist!\n");
			}
		
			
			printf("\tArtist:%s\n \talbumTitle: %s\n \tsongTitle: %s\n \tgenre: %s\n \tSongLength: %d:%d\n \trating: %d\n\n", pCurP->song.artist, pCurP->song.albumTitle, pCurP->song.songTitle, pCurP->song.genre, pCurP->song.length.minutes, pCurP->song.length.seconds, pCurP->song.numberTimesPlayed, pCurP->song.rating);
			pCurP = pCurP->pNext;


		}
		else if (option == 'b') {
		
				
				
				printf("\tArtist:%s\n \talbumTitle: %s\n \tsongTitle: %s\n \tgenre: %s\n \tSongLength: %d:%d\n \trating: %d\n\n", pCurP->song.artist, pCurP->song.albumTitle, pCurP->song.songTitle, pCurP->song.genre, pCurP->song.length.minutes, pCurP->song.length.seconds, pCurP->song.numberTimesPlayed, pCurP->song.rating);
				

				pCurP = pCurP->pPrev;
			}

		}
	}

/*************************************************************
 * Function: count(List *pList)     *
 * Date Created:  9/25/21                                           *
 * Date Last Modified: 9/25/21                                       *
 * Description: This function counts the amount of nodes in the list                   *
 * Input parameters:List* pList                                       *
 * Returns: void                                              *
 * Preconditions:                                        *
 * Postconditions:                                     *
 *************************************************************/
int count(List *pList) {
	int countNum = 1;
	Node* pCur = pList->pHead;
	if (pCur != NULL) {
		while (pCur->pNext != NULL) {
			pCur = pCur->pNext;
			countNum++;
		}
	
	}
	return countNum;

}
/*************************************************************
 * Function: insert(List *pList)    *
 * Date Created:  9/25/21                                           *
 * Date Last Modified: 9/25/21                                       *
 * Description: This function lets the user insert a new record                  *
 * Input parameters:List* pList                                       *
 * Returns: void                                              *
 * Preconditions:                                        *
 * Postconditions:                                     *
 *************************************************************/
Node* insert(List *pList) {
	char dataStr[100];
	int dataNum = 0;
	Record newDataLine = { " " };
	printf("You need to insert information for every detail!\n");

	printf("Artist Name?\n");
	//while (getchar() != '\n');
	gets(dataStr);
	
	strcpy(newDataLine.artist, dataStr);

	printf(" album title?\n");
	//while (getchar() != '\n');
	gets(dataStr);
	
	strcpy(newDataLine.albumTitle, dataStr);

	printf("song title?\n");
	gets(dataStr);
	
	strcpy(newDataLine.songTitle, dataStr);
	printf("Genre?\n");
	gets(dataStr);

	strcpy(newDataLine.genre, dataStr);
	printf("song length? mins\n");
	scanf("%d", &dataNum);
	newDataLine.length.minutes = dataNum;

	printf("song length? Secs\n");
	scanf("%d", &dataNum);
	newDataLine.length.seconds = dataNum;
	printf("number of times played\n");
	scanf("%d", &dataNum);
	newDataLine.numberTimesPlayed = dataNum;
	printf("rating?\n");
	scanf("%d", &dataNum);
	newDataLine.rating = dataNum;

	insertFront(pList, &newDataLine);
}
/*************************************************************
 * Function: deleteNode(List* pList)    *
 * Date Created:  9/25/21                                           *
 * Date Last Modified: 9/25/21                                       *
 * Description: This function lets the user delete a  record                  *
 * Input parameters:List* pList                                       *
 * Returns: void                                              *
 * Preconditions: list must not be empty                                       *
 * Postconditions:                                     *
 *************************************************************/
int deleteNode(List* pList) {
	printList(pList->pHead);
	int success = 0;
		Node* pCur = pList->pHead;
		Node* pPrev = NULL;
	if (pList != NULL) {
		char data[100];
		printf("Which song would you like to delete off your playlist?\n");
		while (getchar() != '\n');
		gets(data);
		if (pCur->pNext == NULL && pCur->pPrev == NULL) {
			free(pCur);
			success = 1;
			pList->pHead = NULL;
			return success;
		}
		while (pCur != NULL && strcmp(pCur->song.songTitle, data) != 0) {
			pCur = pCur->pNext;
			 pPrev = pCur->pPrev;
		}
	
		if (pCur->pPrev == NULL) {
			pList->pHead = pCur->pNext;
			pList->pHead->pPrev = NULL;
			free(pCur);
			success = 1;
		}
		else if (pCur->pNext == NULL) {
			
			//pCur = pCur->pPrev;
			pPrev->pNext = NULL;
			free(pCur);
			success = 1;

		}
		else {
			pCur->pPrev->pNext = pCur->pNext;
			pCur->pNext->pPrev = pCur->pPrev;
			free(pCur);
			success = 1;

		}
	
	}
	else {
		printf("You should try loading first!\nNothing in List...");
	}
	return success;
}
/*************************************************************
 * Function: exitFunc(List* pList)                        *
 * Date Created:  9/11/21                                           *
 * Date Last Modified: 9/13/21                                       *
 * Description: This function exits the program based on user input in main, as well as stores any changes                 *
 * Input parameters: List *pList)                                      *
 * Returns: void                            *
 * Preconditions:                                        *
 * Postconditions:                                   *
 *************************************************************/
void exitFunc(List* pList) {
	//calls store function
	store(pList);
	printf("Thank you for using LLMusicPlayer!\n");
	printf("Your music has been successfully stored!\n");
	exit(0);
}
/*************************************************************
 * Function: Node* editArtist(Node *pNode)                      *
 * Date Created:  9/11/21                                           *
 * Date Last Modified: 9/13/21                                       *
 * Description: This function edits the string artist based on user input                *
 * Input parameters: (Node *pNode) change node directly                                    *
 * Returns: Node                            *
 * Preconditions:                                        *
 * Postconditions:                                   *
 *************************************************************/
	Node* editArtist(Node *pNode) {
		char artist[100];
		printf("what would you like to change artist to?");
		while (getchar() != '\n');
		gets(artist);
		
		//pNode->song.artist = NULL;
		
		strcpy(pNode->song.artist, artist, 50);
			
		
		
			return pNode;
	}
	/*************************************************************
	 * Function: Node* editAlbum(Node* pNode)                    *
	 * Date Created:  9/11/21                                           *
	 * Date Last Modified: 9/13/21                                       *
	 * Description: This function edits the string album based on user input                *
	 * Input parameters: (Node *pNode) change node directly                                    *
	 * Returns: Node                            *
	 * Preconditions:                                        *
	 * Postconditions:                                   *
	 *************************************************************/
	Node* editAlbum(Node* pNode) {
		char artist[100];
		printf("what would you like to change Album to?");
		while (getchar() != '\n');
		gets(artist);

		//pNode->song.artist = NULL;

		strcpy(pNode->song.albumTitle, artist, 50);



		return pNode;
	}
	/*************************************************************
	 * Function: Node* editsongTitle(Node* pNode)                    *
	 * Date Created:  9/11/21                                           *
	 * Date Last Modified: 9/13/21                                       *
	 * Description: This function edits the string title based on user input                *
	 * Input parameters: (Node *pNode) change node directly                                    *
	 * Returns: Node                            *
	 * Preconditions:                                        *
	 * Postconditions:                                   *
	 *************************************************************/

	Node* editsongTitle(Node* pNode) {
		char artist[100];
		printf("what would you like to change songTitle to?");
		while (getchar() != '\n');
		gets(artist);

		//pNode->song.artist = NULL;

		strcpy(pNode->song.songTitle, artist, 50);



		return pNode;
	}
 /*************************************************************
  * Function: Node* editGenre(Node* pNode)                   *
  * Date Created:  9/11/21                                           *
  * Date Last Modified: 9/13/21                                       *
  * Description: This function edits the string genre based on user input                *
  * Input parameters: (Node *pNode) change node directly                                    *
  * Returns: Node                            *
  * Preconditions:                                        *
  * Postconditions:                                   *
  *************************************************************/
	Node* editGenre(Node* pNode) {
		char artist[100];
		printf("what would you like to change genre to?");
		while (getchar() != '\n');
		gets(artist);

		//pNode->song.artist = NULL;

		strcpy(pNode->song.genre, artist, 50);



		return pNode;
	}
	/*************************************************************
	 * Function: Node* editMinutes(Node* pNode)                      *
	 * Date Created:  9/11/21                                           *
	 * Date Last Modified: 9/13/21                                       *
	 * Description: This function edits the int mins based on user input                *
	 * Input parameters: (Node *pNode) change node directly                                    *
	 * Returns: Node                            *
	 * Preconditions:                                        *
	 * Postconditions:                                   *
	 *************************************************************/
	Node* editMinutes(Node* pNode) {
		int min = 0;
		printf("what would you like to change the mins to?");
		while (getchar() != '\n');
		scanf("%d", &min);

		//pNode->song.artist = NULL;

		pNode->song.length.minutes = min;



		return pNode;
	}
	/*************************************************************
	 * Function: Node* editSeconds(Node* pNode)                  *
	 * Date Created:  9/11/21                                           *
	 * Date Last Modified: 9/13/21                                       *
	 * Description: This function edits the int seconds based on user input                *
	 * Input parameters: (Node *pNode) change node directly                                    *
	 * Returns: Node                            *
	 * Preconditions:                                        *
	 * Postconditions:                                   *
	 *************************************************************/
	Node* editSeconds(Node* pNode) {
		int sec = 0;
		printf("what would you like to change the Seconds to?");
		while (getchar() != '\n');
		scanf("%d", &sec);

		//pNode->song.artist = NULL;

		pNode->song.length.seconds = sec;



		return pNode;
	}
	/*************************************************************
	 * Function:Node* editTimesPlayed(Node* pNode)                     *
	 * Date Created:  9/11/21                                           *
	 * Date Last Modified: 9/13/21                                       *
	 * Description: This function edits the int timesPlayed based on user input                *
	 * Input parameters: (Node *pNode) change node directly                                    *
	 * Returns: Node                            *
	 * Preconditions:                                        *
	 * Postconditions:                                   *
	 *************************************************************/
	Node* editTimesPlayed(Node* pNode) {
		int numberTimesPlayed = 0;
		printf("what would you like to change the numberTimesPlayed to?");
		while (getchar() != '\n');
		scanf("%d", &numberTimesPlayed);

		//pNode->song.artist = NULL;

		pNode->song.numberTimesPlayed = numberTimesPlayed;



		return pNode;
	}
	/*************************************************************
	 * Function: Node* editRating(Node* pNode)                     *
	 * Date Created:  9/11/21                                           *
	 * Date Last Modified: 9/13/21                                       *
	 * Description: This function edits the int rating based on user input                *
	 * Input parameters: (Node *pNode) change node directly                                    *
	 * Returns: Node                            *
	 * Preconditions:                                        *
	 * Postconditions:                                   *
	 *************************************************************/
	Node* editRating(Node* pNode) {
		int Rating = 0;
		printf("what would you like to change the rating to?\n");
		//while (getchar() != '\n');
		scanf("%d", &Rating);
		//must check if the rating is inbetween 1-5
		if (Rating > 5 || Rating < 1) {
			printf("RATING MUST BE 1-5\n");
			printf("what would you like to change the rating to?\n");
			while (getchar() != '\n');
			scanf("%d", &Rating);
		}

		//pNode->song.artist = NULL;

		pNode->song.rating = Rating;



		return pNode;
	}