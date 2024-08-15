#include "Path.h"

void Path::addNode(const GraphNode& node, double length) {
        nodes.push_back(node);
        totalLength += length;
    }

    // Get the nodes in the path
    std::vector<GraphNode> Path::getNodes() const {
        return nodes;
    }

    // Get the total length of the path
    double Path::getTotalLength() const {
        return totalLength;
    }

      // size of the path
    int Path::size() const {
		return nodes.size();
	}


  string Path::printPath() {
		stringstream ss;
        for (int i = 0; i < nodes.size()-1; i++)
        {
            for(auto curredge : nodes[i].getNeighbors())
			{
                if (curredge.getDestination() == nodes[i + 1].getName())
                {
                    ss << curredge.printPath();
                }
			}
        }
        if (nodes.size() > 1)
        {
            for (auto curredge : nodes[nodes.size()-1].getNeighbors())
            {
                if (curredge.getDestination() == nodes.front().getName())
                {
                    ss << curredge.printPath();
                }
            }
        }
		return ss.str();
	}