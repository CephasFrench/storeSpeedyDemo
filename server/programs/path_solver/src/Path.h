#pragma once
#include <list>
#include "Node.h"


class Path {
private:
    std::vector<GraphNode> nodes;
    double totalLength;

public:
    // Constructor
    Path() : totalLength(0.0) {}

    // Add a node to the path
    void addNode(const GraphNode& node, double length);

    // Get the nodes in the path
    std::vector<GraphNode> getNodes() const;

    // Get the total length of the path
    double getTotalLength() const;

    // size of the path
    int size() const;

    string printPath();
    
};