/**
    * MICHAEL CALLE - 335 ASSIGNMENT III
    * NEAREST NEIGHBOR ALGORITHM
*/
#ifndef NEARESTNEIGHBOR_HPP
#define NEARESTNEIGHBOR_HPP
#include "Node.hpp"
#include <iostream>
#include <chrono>
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>

/**
    * Traverses the cities using the nearest neighbor algorithm
    * 
    * First, the data from the files are read into a vector. So long as each line begins with a digit
    * the information on that line gets fed into a Node object.
    * These nodes are put together in a vector, that represents the file of data all read in.
    * The following algorithmic process in then timed.
    * Traverse the list and for each node, calculate out of the unvisited nodes which is closest.
    * When that node is discovered std::swap it into the position one ahead of the current node.
    * Naturally, as the vector is traversed the nodes fall into their organized positions.
    *
    * @param filename The file to be read.
*/
void nearestNeighbor (std::string filename){
    //Read data into nodes vector
    std::vector<Node> nodes;
    std::ifstream file; file.open(filename);

    int readID;
    double readX, readY;
    std::string line;
    while(getline(file, line)){
        if(isdigit(line[0])){
            std::stringstream s(line);
            s >> readID;
            s >> readX;
            s >> readY;

            Node node(readID, readX, readY);
            nodes.push_back(node);
        }
    }

    //Starts the timer
    auto start = std::chrono::steady_clock::now();

    //Saving original node
    Node * originalNode = &nodes[0];

    //Initializing ID concatanation
    std::string idList = std::to_string(nodes[0].getID()) + " ";;

    //Sort algorithm
    int save = 0;
    double totalDist = 0;
    for(int i=0;i<nodes.size()-1;i++){
        double dist = pow(2,32);

        for(int j=i+1;j<nodes.size();j++){
            double newDist = nodes[i].getDistance(nodes[j]);
            if(newDist < dist){
                dist = newDist;
                save = j;
            }
        }
        std::swap(nodes[i+1],nodes[save]);

        idList+=std::to_string(nodes[i+1].getID()) + " ";
        totalDist+=dist;
    }

    //Adding the way back to distance
    totalDist+=originalNode->getDistance(nodes[nodes.size()-1]);
    idList+=std::to_string(nodes[0].getID());

    //Ending the timer
    auto finish = std::chrono::steady_clock::now();
    auto number = std::chrono::duration_cast<std::chrono::milliseconds> (finish - start);
    double duration = number.count();

    //Print the final information
    std::cout << idList << "\nTotal Distance: " << totalDist << "\nTime in ms: " << duration << std::endl;
}

#endif