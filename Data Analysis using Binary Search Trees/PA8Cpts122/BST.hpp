#include "TransactionNode.hpp"
#define _CRT_SECURE_NO_WARNINGS

class BST {
public:
	~BST();

	BST();
	void setRoot(Node* newPtr);
	Node* getRoot()const;
	void insert(int units, string newString);
	void inOrderTraversal();
	TransactionNode& findSmallest();
	TransactionNode& findLargest();
private:
	Node* mpRoot;
	void destroyTree(Node* pTree);
	void insert(Node*& pTree, TransactionNode*& node);
	void inOrderTraversal(Node*& pTree);

};