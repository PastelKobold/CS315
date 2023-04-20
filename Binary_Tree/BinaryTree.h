#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<stdio.h>
#include<string>
#include<iomanip>
#include<iostream>

void read(std::string path);

//Could give class node every single function in there and label instead. Having a
//seperate class for everything is over complicated

class node{
    private:
    int key;
    class node *left, *right;
    public:
    void BTInsert();
    /*class BinaryTree{
    private:
    std::string path;
    public:
    void deletion(node object);
    void insertion(node object);
    //search() not sure if I need void or int
};

class RBTree{
    private:

    public:
    void deletion();
    void insertion();
};*/

};

struct node *newNode(int item){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
};



#endif