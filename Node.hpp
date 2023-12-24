/**
    * MICHAEL CALLE - 335 ASSIGNMENT III
    * NEAREST NEIGHBOR ALGORITHM
    * NODE CLASS
*/
#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <math.h>
#include <array>

/*
    * HEADER
*/
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


/*
    * IMPLEMENTATION
*/

/**
    * Default Constructor
*/
Node::Node(){
    ID_ = 8;
    x_ = 16;
    y_ = 32;
}

/**
    * Parameterized Constructor
    *
    * Accepts an array of length 3 of doubles to set the 3 private vars
*/
Node::Node(double data[3]){
    ID_ = data[0];
    x_ = data[1];
    y_ = data[2];
}

/**
    * Parameterized Constructor
    *
    * Sets the private vars to the three params
    *
    * @param a To be set to the ID
    * @param b To be set to x
    * @param c To be set to y
*/
Node::Node(int a, double b, double c){
    ID_ = a;
    x_ = b;
    y_ = c;
}

/**
    * Gets the ID
    * @return The ID
*/
int Node::getID(){
    return ID_;
}

/**
    * Gets the x pos
    * @return The x pos
*/
double Node::getX(){
    return x_;
}

/**
    * Gets the y pos
    * @return The y pos
*/
double Node::getY(){
    return y_;
}

/**
    * Gets the head
    * @return The head
*/
Node *Node::getHead(){
    return head_;
}

/**
    * Gets the tail
    * @return The tail
*/
Node *Node::getTail(){
    return tail_;
}

/**
    * Print statement for node data
    *
    * This concatanates all the data and returns a string
    *
    * @return The ID followed by the coordinate of the node
*/
std::string Node::print(){
    return "ID: " + std::to_string(ID_) + "(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
}


/**
    * Sets the ID
    * @param n The ID
*/
void Node::setID(int n){
    ID_ = n;
}

/**
    * Sets the x pos
    * @param n The x pos
*/
void Node::setX(double n){
    x_ = n;
}

/**
    * Sets the y pos
    * @param n The y pos
*/
void Node::setY(double n){
    y_ = n;
}

/**
    * Sets the head
    * @param n The head
*/
void Node::setHead(Node &n){
    *head_ = n;
}

/**
    * Sets the tail
    * @param n The tail
*/
void Node::setTail(Node &n){
    *tail_ = n;
}

/**
    * Calculates the distance
    *
    * This uses the Pythagorean theorem to return the distance
    * between this node and one other. The result is always
    * positive.
    * 
    * @param node The node to calculate the distance to/from
    * @return The distance between this node and that one.
*/
double Node::getDistance(Node node){
    double xDist = abs(node.getX() - x_);
    double yDist = abs(node.getY() - y_);

    return sqrt(pow(xDist,2) + pow(yDist,2));
}

#endif