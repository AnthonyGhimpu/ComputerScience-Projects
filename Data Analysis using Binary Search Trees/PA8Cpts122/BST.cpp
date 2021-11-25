#include "BST.hpp"

BST::~BST() {
	destroyTree(mpRoot);
}
void BST::destroyTree(Node* pTree) {
	if (pTree != nullptr)
	{
		// recursive
		destroyTree(pTree->getLeft());
		destroyTree(pTree->getRight());
		// process - deleting one node
		delete pTree;
	}
}
BST::BST() {
	mpRoot = nullptr;
}
void BST::setRoot(Node* newPtr) {
	mpRoot = newPtr;
}
Node* BST::getRoot()const {
	return mpRoot;
}
//basic insert
void BST::insert(int units, string newString){
	TransactionNode* node = new TransactionNode(newString,units);
	insert(mpRoot, node);
}

void BST::insert(Node*& pTree, TransactionNode*& pData) {
	if (pTree == nullptr) {//redundant
		mpRoot = new TransactionNode(pData->getData(), pData->getUnits());
	}
	else {
		//so if I try to say pTree-> getUnits, it wouldnt work.
		//The methodology is that I needed to typecast or polymorphically make Node type and typecast it to a transactionNode type in order to gain access to Node's perspective aka the acutal identity tree
		if (pData->getUnits() < (dynamic_cast <TransactionNode*>(pTree))->getUnits()) {
			if (pTree->getLeft() == nullptr) {
				pTree->setLeftNode(new TransactionNode(pData->getData(), pData->getUnits()));
			}
			else {
				insert(pTree->getLeft(), pData);
			}
		}//same thing here
		else if(pData->getUnits() > (dynamic_cast <TransactionNode*>(pTree))->getUnits()){
			if (pTree->getRight() == nullptr) {
				pTree->setRightNode(new TransactionNode(pData->getData(), pData->getUnits()));
			}
			else {
				insert(pTree->getRight(), pData);
			}
		}
		else {
			cout << "Dupe" << endl;
		}
	}
}

void BST::inOrderTraversal() {
	inOrderTraversal(mpRoot);
}
void BST::inOrderTraversal(Node*& pTree) {
	if (pTree != nullptr) {
		inOrderTraversal(pTree->getLeft());
		pTree->printData();
		inOrderTraversal(pTree->getRight());
	}
}
TransactionNode& BST::findSmallest() {
	//since we need to return an acutal TNode, then I needed to have the same identity node by using type casting in order to obtain the acutal information from the TNode itself, as here, we are trying to obtain mUnits
	TransactionNode* pMem = dynamic_cast <TransactionNode*>(mpRoot);
	while (pMem->getLeft() != nullptr) {
		pMem = dynamic_cast <TransactionNode*>(pMem->getLeft());
	}
	return *pMem;
}
TransactionNode& BST::findLargest() {
	TransactionNode* pMem = dynamic_cast <TransactionNode*>(mpRoot);
	while (pMem->getRight() != nullptr) {
		pMem = dynamic_cast <TransactionNode*>(pMem->getRight());
	}
	return *pMem;
}
