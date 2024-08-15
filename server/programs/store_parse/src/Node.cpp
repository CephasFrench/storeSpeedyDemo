#include "Node.h"

vector<Edge> GraphNode::getNeighbors() {
        return this->edges;
    }
    int GraphNode::getID() {
        return ID;
    }
    string GraphNode::getName() const {
        return name;
    }
    void GraphNode::addItems(string item) {
		items.push_back(item);
	}

        std::string GraphNode::printNameAndEdges() {
        std::stringstream ss;

        // Print name
        ss << "node " << name << std::endl;

        // Loop through and print the items
        for (const auto& item : items) {
            ss << item << std::endl;
        }

        // Print edges
        for (auto& edge : edges) {
            ss << "aisles " << edge.getDestination() << " " << edge.getDistance() << std::endl;
            for (auto& path : edge.getPath()) 
            {
				ss << path.first << " " << path.second << endl;
			}
        }

        return ss.str();
    }