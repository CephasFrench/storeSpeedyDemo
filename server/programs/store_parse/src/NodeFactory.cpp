#include "NodeFactory.h"


NodeFactory::NodeFactory() {
        this->id = 0;
    }

    GraphNode NodeFactory::createNode(std::string name, std::vector<Edge> edges, std::vector<std::string> items) {
        this->name = name;
        this->edges = edges;
        this->items = items;
        GraphNode node(id, edges, name, items);
        id++;
        return node; 
    }

    GraphNode NodeFactory::createNode(std::string name, std::vector<Edge> edges) {
        this->name = name;
        this->edges = edges;
        GraphNode node(id, edges, name);
        id++;
        return node;
    }