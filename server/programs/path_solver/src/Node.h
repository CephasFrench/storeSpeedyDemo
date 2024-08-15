#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "Edge.h"

using namespace std;

class GraphNode {
public:
    GraphNode(int ID, vector<Edge> edges, string name, vector<string> items) : ID(ID), edges(edges), name(name), items(items) {}
    GraphNode(int ID, vector<Edge> edges, string name) : ID(ID), edges(edges), name(name){}
    GraphNode() {};
    vector<Edge> getNeighbors();
    int getID();
    string getName() const ;
    void addItems(string item);

    std::string printNameAndEdges();
    
private:
    int ID;
    string name;
    vector<Edge> edges;
    vector<string> items;
};