#ifndef NODE_HPP
#define NODE_HPP
#include <array>

class Node{
    private:
        int ID_;
        double x_;
        double y_;
        Node *head_;
        Node *tail_;
    public:
        //Constructors
        Node();
        Node(double data[3]);
        Node(int a, double b, double c);

        //Accessor
        int getID();
        double getX();
        double getY();
        Node *getHead();
        Node *getTail();
        std::string print();

        //Mutator
        void setID(int n);
        void setX(double n);
        void setY(double n);
        void setHead(Node &n);
        void setTail(Node &n);

        double getDistance(Node node);
};

#include "Node.cpp"
#endif