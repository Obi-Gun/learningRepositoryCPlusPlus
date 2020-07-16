#ifndef BinaryTreeClass
#define BinaryTreeClass
#include "ListBiDirectional.h"
#include "String_obi.h"

struct elementBinaryTree {
	String_obi* key_; // Car number
	ListBiDirectional<String_obi>* list_;
	elementBinaryTree* left_, * right_, * parent_;

	elementBinaryTree(char* key, elementBinaryTree* left = nullptr, elementBinaryTree* right = nullptr, elementBinaryTree* parent = nullptr);
	elementBinaryTree(const char* key, elementBinaryTree* left = nullptr, elementBinaryTree* right = nullptr, elementBinaryTree* parent = nullptr);
	elementBinaryTree(String_obi key, elementBinaryTree* left = nullptr, elementBinaryTree* right = nullptr, elementBinaryTree* parent = nullptr);
	~elementBinaryTree();
};

class BinaryTree
{
private:
	elementBinaryTree* root_;

public:
	BinaryTree();
	~BinaryTree();

	void print(bool withList = false);
	void print(elementBinaryTree* Node, bool withList = false);

	elementBinaryTree* search(const char* key);

	//min from current element
	//elementBinaryTree* min(elementBinaryTree* Node);

	//max from current element
	//elementBinaryTree* max(elementBinaryTree* Node);

	//next for current element
	//elementBinaryTree* next(elementBinaryTree* Node);

	//previous for current element
	//elementBinaryTree* previous(elementBinaryTree* Node);

	void insert(elementBinaryTree* z);

	//delete current element
	//0 - for delete all tree
	//void del(elementBinaryTree* z = 0);

	//elementBinaryTree* getRoot();

};
#endif