#include <iostream>
#include "storeGraphFactory.h"

int main() {
    StoreGraphFactory myStoreGraphFactory;
    StoreGraph myGraph = myStoreGraphFactory.getGraph("storedata.txt");
    cout << "about to solve for path!" << endl;
    Path path = myGraph.FindPath();
     ofstream output("paths.txt");
    if (!output)
    {
        cout << "failed to open file" << endl;
        return 1;
    }

    output << path.printPath();
    output.close();

    return 0;
}