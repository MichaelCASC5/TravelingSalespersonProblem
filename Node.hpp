#ifndef NODE_HPP
#define NODE_HPP
#include <array>

class Node{
    private:
        int ID_;
        int x_;
        int y_;
    public:
        //Constructors
        Node();
        Node(int a, int b, int c);

        //Accessor
        int getID();
        int getX();
        int getY();

        //Mutator
        void setID(int n);
        void setX(int n);
        void setY(int n);

        double getDistance(Node node);
};

#include "Node.cpp"
#endif