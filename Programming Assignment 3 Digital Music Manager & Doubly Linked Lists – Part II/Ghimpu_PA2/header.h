#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct duration {
	 int minutes;
	 int seconds;
}Duration;

typedef struct record {
	char artist[50];
	char albumTitle[50];
	char songTitle[50];
	char genre[50];
	Duration length;
	int numberTimesPlayed;
	int rating;

}Record;


typedef struct node {
	Record song;
	struct node* pNext;
	struct node* pPrev;

}Node;

typedef struct list {
	Node* pHead; 
}List;

Node* makeNode(const Record* pNewData);
void printList(Node* pNode);
Node* swap(List* Plist, Node* pCur, Node* tempNode);
void sortMenu(List* pList);
Node* sortByArtist(List* pList);
Node* sortByAlbum(List* pList);
Node* sortByRating(List* pList);
Node* sortByAmtTimesPlayed(pList);
int insertFront(List* pList, const Record* pNewData);
Node* load(Node* pList, const Record* pNewdata);
void display(List* pList);
void edit(List* pList);
int play(List* pList);
Node* rate(List* pList);
Node* shuffle(List* pList);
void interatePrint(List* pList);
int count(List* pList);
Node* insert(List* pList);
int deleteNode(List* pList);
void exitFunc(List* pList);
void store(Node* pNode);
Node* editArtist(List* pNode);
Node* editAlbum(Node* pNode);
Node* editsongTitle(Node* pNode);
Node* editGenre(Node* pNode);
Node* editMinutes(Node* pNode);
Node* editSeconds(Node* pNode);
Node* editTimesPlayed(Node* pNode);
Node* editRating(Node* pNode);
#endif