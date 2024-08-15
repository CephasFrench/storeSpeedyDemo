#include "Edge.h"
		// Get the path from the source to the destination
		vector<pair<int,int>> Edge::getPath() const {
			return edges.second;
		}

		string Edge::printEdge() {
			stringstream ss;
			ss << "Destination: " << destination << " Distance: " << std::setprecision(2) << edges.first << " Path: ";
			for (auto path : edges.second) {
				ss << path.first << " " << path.second << " ";
			}
			return ss.str();
		}

		string Edge::printPath()
			{
			stringstream ss;
			for (auto path : edges.second) {
				ss << path.first << " " << path.second << endl;
			}
			return ss.str();
		}

		void Edge::setDestination(string destination) {
			this->destination = destination;
		}

		double Edge::getDistance() const {
			return edges.first;
		}

		string Edge::getDestination() const {
			return destination;
		}
