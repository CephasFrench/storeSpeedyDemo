#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "StoreGraph.h"
#include "NodeFactory.h"
using namespace std;
class StoreGraphFactory {
public:
    // TODO: Add function declarations here
    StoreGraph getGraph(const std::string& fileName);
    StoreGraph getGraph(stringstream input);

private:
    // TODO: Add private member variables here
};