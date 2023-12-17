#pragma once
#include "BinaryTree.h"

template <typename T>
BinaryTree<T>::BinaryTree()
	: root{ nullptr }, size{} {}

template<typename T>
inline Node<T>* BinaryTree<T>::Root()
{
	return root;
}

template<typename T>
inline int BinaryTree<T>::Size()
{
	return size;
}

template<typename T>
inline Node<T>* BinaryTree<T>::CreateNode(Node<T>* parent, T value)
{
	Node<T>* node = new Node<T>;
	node->value = value;
	node->parent = parent;
	return node;
}

template<typename T>
inline void BinaryTree<T>::AddLoop(T value)
{
	if (!root)
	{
		root = CreateNode(nullptr, value);
		size = 1;
		return;
	}

	Node<T>* nodeParent = nullptr;
	Node<T>* nodeCurrent = root;

	while (nodeCurrent)
	{
		nodeParent = nodeCurrent;
		if (value < nodeCurrent->value)
			nodeCurrent = nodeCurrent->leftChild;
		else
			nodeCurrent = nodeCurrent->rightChild;
	}

	nodeCurrent = CreateNode(nodeParent, value);
	if (value <= nodeParent->value)
		nodeParent->leftChild = nodeCurrent;
	else
		nodeParent->rightChild = nodeCurrent;

	size++;
}

template<typename T>
inline void BinaryTree<T>::AddReq(T value, Node<T>* node)
{
	if (!root)
	{
		root = CreateNode(nullptr, value);
		size = 1;
		return;
	}

	if (!node)
		node = root;

	if (value <= node->value)
	{
		if (node->leftChild)
			AddReq(value, node->leftChild);
		else
		{
			node->leftChild = CreateNode(node, value);
			size++;
		}
	}
	else
	{
		if (node->rightChild)
			AddReq(value, node->rightChild);
		else
		{
			node->rightChild = CreateNode(node, value);
			size++;
		}
	}
}

template<typename T>
inline void BinaryTree<T>::ListBranch(Node<T>* node)
{
	if (node)
	{
		ListBranch(node->leftChild);
		std::cout << node->value << " ";
		ListBranch(node->rightChild);
	}
}

template<typename T>
inline void BinaryTree<T>::List()
{
	ListBranch(root);
}
