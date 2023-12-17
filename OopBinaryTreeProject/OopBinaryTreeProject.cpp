#include <iostream>
#include "BinaryTree.h"

int main()
{
    BinaryTree<int> tree;

    /*tree.AddLoop(20);
    tree.AddLoop(10);
    tree.AddLoop(30);
    tree.AddLoop(5);
    tree.AddLoop(25);
    tree.AddLoop(15);
    tree.AddLoop(35);*/

    tree.AddReq(20);
    tree.AddReq(10);
    tree.AddReq(30);
    tree.AddReq(5);
    tree.AddReq(25);
    tree.AddReq(15);
    tree.AddReq(35);

    tree.AddLoop(18);

    tree.List();
    std::cout << "\n";

    Node<int>* nodeDel = tree.Find(20);
    tree.DeleteNode(nodeDel);
    //tree.DeleteNode(tree.Find(25));

    tree.List();
    std::cout << "\n";
}
