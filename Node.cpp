#include <iostream>
#include <math.h>

Node::Node(){
    ID_ = 8;
    x_ = 16;
    y_ = 32;
}

Node::Node(double data[3]){
    ID_ = data[0];
    x_ = data[1];
    y_ = data[2];
}

Node::Node(int a, double b, double c){
    ID_ = a;
    x_ = b;
    y_ = c;
}

int Node::getID(){
    return ID_;
}

double Node::getX(){
    return x_;
}

double Node::getY(){
    return y_;
}

Node *Node::getHead(){
    return head_;
}

Node *Node::getTail(){
    return tail_;
}

std::string Node::print(){
    // return "ID: " << ID_ << "(" << x_ << ", " << y_ << ")";
    return "ID: " + std::to_string(ID_) + "(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
}



void Node::setID(int n){
    ID_ = n;
}

void Node::setX(double n){
    x_ = n;
}

void Node::setY(double n){
    y_ = n;
}

void Node::setHead(Node &n){
    *head_ = n;
}

void Node::setTail(Node &n){
    *tail_ = n;
}

double Node::getDistance(Node node){
    double xDist = abs(node.getX() - x_);
    double yDist = abs(node.getY() - y_);

    return sqrt(pow(xDist,2) + pow(yDist,2));
}