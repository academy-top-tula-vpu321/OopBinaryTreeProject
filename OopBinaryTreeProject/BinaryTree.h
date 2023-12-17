#pragma once
template <typename T>
struct Node
{
	Node<T>* parent = nullptr;
	T value;
	Node<T>* leftChild = nullptr;
	Node<T>* rightChild = nullptr;
};

template <typename T>
class BinaryTree
{
	Node<T>* root;
	int size;

public:
	BinaryTree();
	Node<T>* Root();
	int Size();

	Node<T>* CreateNode(Node<T>* parent, T value);

	void AddLoop(T value);
	void AddReq(T value, Node<T>* node = nullptr);

	Node<T>* Find(T value);

	Node<T>* MinBranch(Node<T>* node = nullptr);
	Node<T>* MaxBranch(Node<T>* node = nullptr);

	void DeleteNode(Node<T>* node);
	void DeleteBranch(Node<T>* node);

	void ListBranch(Node<T>* node);
	void List();
};

#include "BinaryTree.inl"
