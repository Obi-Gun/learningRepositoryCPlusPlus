#include "BinaryTree.h"
#include <iostream>

elementBinaryTree::elementBinaryTree(char* key, elementBinaryTree* left, elementBinaryTree* right, elementBinaryTree* parent)
{
	key_ = new String_obi(key);
	list_ = new ListBiDirectional<String_obi>;
	left_ = left;
	right_ = right;
	parent_ = parent;
}

elementBinaryTree::elementBinaryTree(const char* key, elementBinaryTree* left, elementBinaryTree* right, elementBinaryTree* parent)
{
	key_ = new String_obi(key);
	list_ = new ListBiDirectional<String_obi>;
	left_ = left;
	right_ = right;
	parent_ = parent;
}

elementBinaryTree::elementBinaryTree(String_obi key, elementBinaryTree* left, elementBinaryTree* right, elementBinaryTree* parent)
{
	key_ = new String_obi(key);
	list_ = new ListBiDirectional<String_obi>;
	left_ = left;
	right_ = right;
	parent_ = parent;
}

elementBinaryTree::~elementBinaryTree()
{
	std::cout << "\n~elementBinaryTree()";
	key_->~String_obi();
}

BinaryTree::BinaryTree()
{
	root_ = nullptr;
}

BinaryTree::~BinaryTree()
{
	//this->del();
}

void BinaryTree::print(bool withList)
{
	print(root_, withList);
}

void BinaryTree::print(elementBinaryTree* node, bool withList)
{
	if (node != nullptr) {
		print(node->left_, withList);
		std::cout << std::endl << "_______car number: ";
		node->key_->print();
		std::cout << " _______" << std::endl;
		if (withList) {
			node->list_->print();
		}
		print(node->right_, withList);
	}
}

elementBinaryTree* BinaryTree::search(const char* key)
{
	elementBinaryTree* node = root_;
	while (node != nullptr && strcmp(key, node->key_->getCharArr()) != 0) {
		if (strcmp(key, node->key_->getCharArr()) < 0) {
			node = node->left_;
		}
		else {
			node = node->right_;
		}
	}
	return node;
}

void BinaryTree::insert(elementBinaryTree* z)
{
	z->left_ = nullptr;
	z->right_ = nullptr;
	elementBinaryTree* parentCurEl = nullptr;
	elementBinaryTree* curEl = root_;
	while (curEl != nullptr) {
		parentCurEl = curEl;
		if (strcmp(z->key_->getCharArr(), curEl->key_->getCharArr()) < 0) {
			curEl = curEl->left_;
		}
		else {
			curEl = curEl->right_;
		}
	}
	z->parent_ = parentCurEl;
	if (parentCurEl == nullptr) {
		root_ = z;
	}
	else if (strcmp(z->key_->getCharArr(), parentCurEl->key_->getCharArr()) < 0) {
		parentCurEl->left_ = z;
	}
	else {
		parentCurEl->right_ = z;
	}
}
