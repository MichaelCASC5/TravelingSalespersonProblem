#include <iostream>
#include <math.h>

Node::Node(){
    ID_ = 8;
    x_ = 16;
    y_ = 32;
}

Node::Node(int a, int b, int c){
    ID_ = a;
    x_ = b;
    y_ = c;
}

int Node::getID(){
    return ID_;
}

int Node::getX(){
    return x_;
}

int Node::getY(){
    return y_;
}

void Node::setID(int n){
    ID_ = n;
}

void Node::setX(int n){
    x_ = n;
}

void Node::setY(int n){
    y_ = n;
}

double Node::getDistance(Node node){
    double xDist = abs(node.getX() - x_);
    double yDist = abs(node.getY() - y_);

    return sqrt(pow(xDist,2) + pow(yDist,2));
}