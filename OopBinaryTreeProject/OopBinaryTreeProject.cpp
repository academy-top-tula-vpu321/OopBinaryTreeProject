#include <iostream>
#include "BinaryTree.h"

int main()
{
    BinaryTree<int> tree;

    tree.AddLoop(20);
    tree.AddLoop(10);
    tree.AddLoop(30);
    tree.AddLoop(5);
    tree.AddLoop(25);
    tree.AddLoop(15);
    tree.AddLoop(35);

    tree.List();
}
