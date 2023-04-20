
#include<stdio.h>
#include<fstream>
#include<string>
#include<iomanip>
#include<iostream>
#include<vector>

void read(std::string path){
    std::ifstream dataFile (path);

    std::string dataFileLine;

    std::getline(dataFile, dataFileLine);

    while(std::getline(dataFile, dataFileLine)) {
        dataFileLines.push(dataFileLine);
    }
};

void node::BTInsertion(){
    if(node == NULL) 
        return createNode(data);
    if (data < node->data)
        node->left  = BinaryTree.insertion(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);  
    return node;
};