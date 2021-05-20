#include <iostream>
#include "dslab3.h"
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;

int main()
{
    Node* root = nullptr;
    Tree tree;
    high_resolution_clock::duration totalTimeAdd(0);
    auto start1 = high_resolution_clock::now();
    for (int i = 0; i < 7; i++) {
        root = tree.insert(root, i, 20);
    }
    auto end1 = high_resolution_clock::now();
    totalTimeAdd = totalTimeAdd + (end1 - start1);

    high_resolution_clock::duration totalTimeDel(0);
    auto start2 = high_resolution_clock::now();
    for (int i = 0; i < 0; i++) {
        tree.deleteNode(root, i);
    }
    auto end2 = high_resolution_clock::now();
    totalTimeDel = totalTimeDel + (end2 - start2);

    typedef std::chrono::milliseconds ms;
    ms tAdd = std::chrono::duration_cast<ms>(totalTimeAdd);
    ms tDel = std::chrono::duration_cast<ms>(totalTimeDel);
    cout << "Time to add: " << tAdd.count() << " milliseconds."<< "\nTime to delete: " << tDel.count() << " milliseconds." << endl;
    //tree.print(root);
    //cout << endl << root->getBalance(root);
    cout << "Height of tree is: " << root->getHeight() << endl;
    cout << tree.getNodes() << " nodes\n";
    tree.print(root);
    return 0;
}
