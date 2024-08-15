#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;
class Edge
{
	public:
		Edge(string destination, pair<double, vector<pair<int, int>>> edges): destination(destination), edges(edges) {}
		Edge(pair<double, vector<pair<int, int>>> edges) : destination("NOTSET"), edges(edges) {}
		Edge(string destination, double distance) : destination(destination) {
			edges.first = distance;
		}

		double getDistance() const;

		string getDestination() const;


		// Get the path from the source to the destination
		vector<pair<int,int>> getPath() const;

		string printEdge();

		string printPath();

		void setDestination(string destination);

private:
	// Name of the node that this edge connects to
	string destination;
	// This is the total distance from the source to the destination and the path
	pair<double,vector<pair<int,int>>> edges;
};

