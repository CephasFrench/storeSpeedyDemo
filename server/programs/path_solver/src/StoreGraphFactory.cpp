#include "StoreGraphFactory.h"

 StoreGraph StoreGraphFactory::getGraph(stringstream input)
{
        // Create a vector to store the nodes
        std::vector<GraphNode> nodes;

        // Read the file word by word
        std::string word;
        input >> word;
        NodeFactory nodeFactory;
        while (true) {
            // Process each word of the file
            // TODO: Implement your logic here
            if (word == "node")
            {
                // Get name
                string name;
                input >> name;
                // loop though and get all the items
                vector<string> items;
                while (input >> word)
                {
                    if (word == "aisles")
                    {
                        break;
                    }
                    items.push_back(word);
                }
                // loop though and get all the aisles
                vector<Edge> edges;
                while (true)
                {
                    if (word == "node" || word == "exit")// std::all_of(word.begin(), word.end(), ::isdigit))
                    {
                        break;
                    }

                    //string aisle = word;
                    string aisle;
                    input >> aisle;
                    int distance;
                    input >> distance;
                    // Now we known that the next word is a cordinate
                    vector<pair<int, int>> cordinates;
                    input >> word;
                    while (word != "aisles" and word != "node" and word != "exit")
                    {
                        pair<int, int> cordinate;
                        cordinate.first = stoi(word);
                        input >> word;
                        cordinate.second = stoi(word);
                        cordinates.push_back(cordinate);
                        input >> word;
                    }

                    //edges.push_back(make_pair(aisle, distance));
                    edges.push_back(Edge(aisle, make_pair(distance, cordinates)));
                    //input >> word;
                }
                // Now have all the data to create a node
                GraphNode node = nodeFactory.createNode(name, edges, items);
                // Add node to vector
                nodes.push_back(node);

            }
            else if (word == "exit")
            {
                break;
            }
            else
            {
                // Handle the error, e.g., throw an exception or return an error code
                throw std::runtime_error("Invalid sstream format");
            }
        }
        // DONE: Send data to NodeFactory to create nodes - this is done in the input loop

        // TODO: Create a StoreGraph object with the nodes in a vector
        StoreGraph storeGraph(nodes);

        // TODO: Return the StoreGraph object
        return storeGraph;
    }
    StoreGraph StoreGraphFactory::getGraph(const std::string& filename) {
    // Open the file
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Unable to open file");
    }

    // Create a vector to store the nodes
    std::vector<GraphNode> nodes;

    // Read the file word by word
    std::string word;
    file >> word;
    NodeFactory nodeFactory;
    while (true) {
        // Process each word of the file
        if (word == "node") {
            // Get name
            std::string name;
            file >> name;

            // Loop through and get all the items
            std::vector<std::string> items;
            while (file >> word) {
                if (word == "aisles") {
                    break;
                }
                items.push_back(word);
            }

            // Loop through and get all the aisles
            std::vector<Edge> edges;
            while (true) {
                if (word == "node" || word == "exit") {
                    break;
                }

                std::string aisle;
                file >> aisle;
                int distance;
                file >> distance;

                // Now we know that the next word is a coordinate
                std::vector<std::pair<int, int>> coordinates;
                file >> word;
                while (word != "aisles" && word != "node" && word != "exit") {
                    std::pair<int, int> coordinate;
                    coordinate.first = std::stoi(word);
                    file >> word;
                    coordinate.second = std::stoi(word);
                    coordinates.push_back(coordinate);
                    file >> word;
                }

                edges.push_back(Edge(aisle, std::make_pair(distance, coordinates)));
            }

            // Now have all the data to create a node
            GraphNode node = nodeFactory.createNode(name, edges, items);
            // Add node to vector
            nodes.push_back(node);

        }
        else if (word == "exit") {
            break;
        }
        else {
            // Handle the error, e.g., throw an exception or return an error code
            throw std::runtime_error("Invalid file format");
        }
        if (file.peek() == EOF) {
            break;
        }
    }

    // Create a StoreGraph object with the nodes in a vector
    StoreGraph storeGraph(nodes);

    // Return the StoreGraph object
    return storeGraph;
}