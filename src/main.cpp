#include "display/TreeViewer.h"
#include "tree/Tree.h"
#include "tree/Node.h"
#include "tree/Bud.h"
#include <memory>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(int argc, char **argv) {
    unique_ptr<TreeViewer> viewer(new TreeViewer());
    unique_ptr<Tree> tree(new Tree());

    int growCount = 0;
    if (argc > 1) {
        growCount = atoi(argv[1]);
        cout << "Grow Count: " << growCount << endl;
    }

    for (int i=0; i<growCount; i++) {
        tree->grow();
        cout << "Grow: " << i+1 << endl;
    }
    cout << "Exiting" << endl;
    //tree->print();
    viewer->AddTree(tree.get());

    while (true) {
        viewer->draw();
    }
}
