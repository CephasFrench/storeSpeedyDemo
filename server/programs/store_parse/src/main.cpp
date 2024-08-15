#include <iostream>
#include <fstream>
#include <string>
#include "Maze.h"

int main() {
    Maze maze;

    maze.start("vmstoretext_readable.txt");

    std::ofstream outputFile("storedata.txt");
    if (outputFile.is_open()) {
        outputFile << maze.getNodeData().str();
        outputFile.close();
    } else {
        std::cout << "Failed to open file for writing." << std::endl;
    }
    
    return 0;
}