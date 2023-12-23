#ifndef NEARESTNEIGHBOR_HPP
#define NEARESTNEIGHBOR_HPP
#include "Node.hpp"
#include <chrono>
#include <cmath>
#include <fstream>
#include <sstream>

void read(std::vector<Node> & nodes, std::string filename){
    std::ifstream file; file.open(filename);

    double data[3];
    std::string line;
    while(getline(file, line)){
        if(isdigit(line[0])){
            std::stringstream s(line);
            s >> data[0];
            s >> data[1];
            s >> data[2];

            Node node(data);
            nodes.push_back(node);
        }
    }
}

void nearestNeighbor (std::string filename){
    //Read data into nodes vector
    std::vector<Node> nodes;
    read(nodes,filename);

    //Starts the timer
    auto start = std::chrono::steady_clock::now();

    //Saving original node
    Node * originalNode = &nodes[0];

    //Initializing ID concatanation
    std::string idList = "1 ";

    //Sort algorithm
    int save = 0;
    double totalDist = 0;
    for(int i=0;i<nodes.size()-1;i++){
        // if(i%100==0)std::cout << i << std::endl;
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

    std::cout << idList << "\nTotal Distance: " << totalDist << "\nTime in ms: " << duration << std::endl;
}

#endif