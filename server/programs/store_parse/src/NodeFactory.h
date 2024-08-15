#ifndef NODE_FACTORY_H
#define NODE_FACTORY_H

#include <vector>
#include <utility> // Include the utility header for std::pair
#include "Node.h"

struct NodeFactory {
    int id;
    std::string name;
    std::vector<Edge> edges; // Use std::pair<Node, int> instead of Edge
    std::vector<std::string> items; // New vector of strings called items

    NodeFactory();

    GraphNode createNode(std::string name, std::vector<Edge> edges, std::vector<std::string> items);

    GraphNode createNode(std::string name, std::vector<Edge> edges);
};

#endif // NODE_FACTORY_H