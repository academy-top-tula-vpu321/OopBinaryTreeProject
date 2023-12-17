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
inline Node<T>* BinaryTree<T>::Find(T value)
{
	Node<T>* nodeCurrent = root;
	while (nodeCurrent)
	{
		if (nodeCurrent->value == value)
			return nodeCurrent;
		else
		{
			if (value <= nodeCurrent->value)
				nodeCurrent = nodeCurrent->leftChild;
			else
				nodeCurrent = nodeCurrent->rightChild;
		}
	}

	return nullptr;
}

template<typename T>
inline Node<T>* BinaryTree<T>::MinBranch(Node<T>* node)
{
	if (!node)
		node = root;
	while (node->leftChild)
		node = node->leftChild;

	return node;
}

template<typename T>
inline Node<T>* BinaryTree<T>::MaxBranch(Node<T>* node)
{
	if (!node)
		node = root;
	while (node->rightChild)
		node = node->rightChild;

	return node;
}

template<typename T>
inline void BinaryTree<T>::DeleteNode(Node<T>* node)
{
	// delete leaf
	if (!node->leftChild && !node->rightChild)
	{
		if (node == root)
			root = nullptr;
		else
		{
			if (node->parent->leftChild == node)
				node->parent->leftChild = nullptr;
			else
				node->parent->rightChild = nullptr;
		}

		delete node;
		size--;
		return;
	}

	// delete node with single child
	if ((bool)node->leftChild ^ (bool)node->rightChild)
	{
		Node<T>* nodeChild;
		if (node->leftChild)
			nodeChild = node->leftChild;
		else
			nodeChild = node->rightChild;

		if (node == root)
		{
			root = nodeChild;
			nodeChild->parent = nullptr;
		}
		else
		{
			if (node->parent->leftChild == node)
				node->parent->leftChild = nodeChild;
			else
				node->parent->rightChild = nodeChild;
			nodeChild->parent = node->parent;
		}

		delete node;
		size--;
		return;
	}

	// delete node with pair chidrens;
	Node<T>* nodeMinRight = MinBranch(node->rightChild);
	node->value = nodeMinRight->value;
	DeleteNode(nodeMinRight);
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
