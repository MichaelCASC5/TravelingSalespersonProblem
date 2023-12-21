#include <iostream>
#include "NearestNeighbor.hpp"
#include "GreedyTSP.hpp"
#include "Node.hpp"

int main(){
    std::cout << "hi" << std::endl;
    std::string test;
    nearestNeighbor(test);
    greedyTSP(test);

    Node node(1,200,200);
    Node other(2,300,300);

    std::cout << node.getDistance(other) << std::endl;
    
    return 0;
}