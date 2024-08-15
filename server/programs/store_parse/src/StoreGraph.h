#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Node.h"
#include "Path.h"
#include <vector>
#include <string>

using namespace std;

class StoreGraph {
private:

public:
    std::vector<GraphNode> nodes;
    StoreGraph(const std::vector<GraphNode>& nodes) : nodes(nodes) {
        // Constructor implementation
        myNodes = nodes;
    }

    double getTotalDistance();

    Path FindPath();

private:
    vector<GraphNode> myNodes;
    Path shortestPath;
    GraphNode startNode;

    void pathCall(vector<GraphNode> nodes, GraphNode previousNode, Path currentPath);
};