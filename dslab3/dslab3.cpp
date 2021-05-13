#include <iostream>
#include "dslab3.h"

int main()
{
    Node* root = nullptr;
    Tree tree;
    root = tree.insert(root, 30, 20);
    root = tree.insert(root, 50, 20);
    root = tree.insert(root, 70, 20);
    root = tree.insert(root, 70, 20);
    root = tree.insert(root, 20, 20);
    root = tree.insert(root, 25, 20);
    root = tree.insert(root, 15, 20);
    tree.print(root);
    cout << "Height of tree is: " << root->getHeight();
    return 0;
}
