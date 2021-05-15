#include <iostream>
#include "dslab3.h"
using namespace std;

int main()
{
    Node* root = nullptr;
    Tree tree;
    for (int i = 0; i < 10000; i++) {
        root = tree.insert(root, i, 20);
    }
    tree.deleteNode(root, 2);
    tree.deleteNode(root, 2);

    //tree.print(root);
    //cout << endl << root->getBalance(root);
    cout << "Height of tree is: " << root->getHeight() << endl;
    cout << tree.getNodes() << " nodes\n";
    return 0;
}
