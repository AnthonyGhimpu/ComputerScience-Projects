#include "BST.hpp"

#define _CRT_SECURE_NO_WARNINGS

//look over BST definition in constructor (const)
BST::BST() {
	
	mpRoot = nullptr;
	infile = openFile();
	char data;
	string morse;
	BSTNode *temp = new BSTNode(data, morse);
	for (int i = 1; i <= 39; i++) {
		infile >> *temp;
		insert(mpRoot, temp);
	}
	inOrderPrint(mpRoot);
	letterOpen(mpRoot);

	infile.close();
}

void BST::insert(BSTNode* pTree,  BSTNode* node) {
	if (pTree == nullptr) {
		mpRoot = new BSTNode(node->getChar(), node->getString());
	}
	else {
		if (pTree->getChar() > node->getChar()) {
			if (pTree->getLeftPtr() == nullptr) {
				pTree->setLeftPtr(new BSTNode(node->getChar(), node->getString()));
			}
			else {
				insert(pTree->getLeftPtr(), node);
			}
		}
		else if (pTree->getChar() < node->getChar()) {
			if (pTree->getRightPtr() == nullptr) {
				pTree->setRightPtr(new BSTNode(node->getChar(), node->getString()));
			}
			else {
				insert(pTree->getRightPtr(), node);
			}
		}else{
			cout << "Dupe" << endl;
		}
	}
}
void BST::inOrderPrint(BSTNode* pTree) {
	if (pTree != nullptr) {
		inOrderPrint(pTree->getLeftPtr());
		cout << "Letter: " << pTree->getChar() << endl;
		cout << "Morse: " << pTree->getString() << endl<<endl;
		inOrderPrint(pTree->getRightPtr());
	}
}

void BST::letterOpen(BSTNode* pTree) {
	fstream infile;
	string file = "Convert.txt";
	infile.open(file.c_str(), std::ios::in);
	char dataLine[100] = "";
	while (!infile.eof()) {
		infile.getline(dataLine, 100);


		int i = 0;
		while (dataLine[i] != '\0') {
			dataLine[i++] = toupper((unsigned char)dataLine[i]);
		}
		string morse;
		char letter;
		for (int i = 0; dataLine[i] != '\0'; i++) {
			letter = dataLine[i];
			morse = search(pTree, letter);
			printString(morse);
		}
		cout << endl;
	}
	infile.close();
}
void BST::printString(string morse) const {
	cout << morse;
}

string BST::search(BSTNode* pTree, char letter) const  {
	if (pTree != nullptr) {
		if (pTree->getChar() == letter) {
			return pTree->getString();
		}
		else {
			if (pTree->getChar() > letter) {
				return search(pTree->getLeftPtr(), letter);

			}
			else {
				return search(pTree->getRightPtr(), letter);
			}
		}
	}
	else {
		return " ";
	}
}

	

BST::~BST() {
	destroyTree(this->mpRoot);
}

void BST::destroyTree(BSTNode* pTree) {
	if (pTree != nullptr)
	{
		// recursive
		destroyTree(pTree->getLeftPtr());
		destroyTree(pTree->getRightPtr());
		// process - deleting one node
		delete pTree;
	}
}


fstream BST::openFile() {
	//opens file for exercise plan
	fstream infile;
	string fileNameMorse = "MorseTable.txt";
	//reading file
	infile.open(fileNameMorse.c_str(), std::ios::in);
	if (infile.is_open()) {
		return infile;
	}
	else {
		cout << "Error opening file!" << endl;
	}

}

