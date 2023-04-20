#include"Nodes.h"
#include<iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <queue>
#include <vector>
#include<fstream>
#include<sstream>

int RBTree::getsize(){
    return nodes.size();
}

Node* RBTree::getRoot(){
    return root;
}

void RBTree::fileRead(){
    std::string temp;
    nodes.clear();
    std::string filename;
    std::cout << "Enter the file name: ";
    std::cin >> filename;

    std::ifstream file;
    file.open(filename);
    if (file.is_open()) {
        std::string line = "";
        getline(file, line);

        while (getline(file, line)) {
            std::stringstream input(line);

            int node;

            getline(input, temp, ',');
            node = atof(temp.c_str());

            nodes.push_back(node);

            line = "";
        }
        file.close();
    } else {
        std::cout << "Error: Unable to open the file " << filename << std::endl;
    }
    /*std::cout << "Test print:" << std::endl;
    for (int i = 0; i < nodes.size(); i++) {
        std::cout << nodes.at(i) << " ";
    }*/
    std::cout << std::endl;
};

void RBTree::inorderTraversal(Node *root){
    if(root == NULL){
        std::cout << "Error";
        return;
    }
    /*inorderTraversal(root->left);
    std::cout << root->key << " ";
    inorderTraversal(root->right);*/
    if (root != NULL) {
    // Traverse left
    inorderTraversal(root->left);

    // Traverse root
    std::cout << root->key << " -> ";

    // Traverse right
    inorderTraversal(root->right);
  }
}

int RBTree::search(const int key){
    Node* x = root;
    while(x != NULL){
        if(key == x->key)
            //return x->val;
            return key;
        if(key > x->key)
            x = x->left;
        else
            x = x->right;
    }
    return NULL;
}

Node* RBTree::fixUp(Node* n){
    if(n->right->color == true)
        n = rotateLeft(n);

    if((n->left->color == true) && (n->left->left->color == true))
        n = rotateRight(n);
    
    if((n->left->color == true) && (n->right->color == true))
        colorFlip(n);

    return n;
}

void RBTree::insertion(int key /*int val*/){
    root = insertion(root, key /*val*/);
    root->color = true;
}

Node* RBTree::insertion(Node* n, int key/*int val*/){
    if(n == NULL)
        return newNodeRB(key/*val*/);

    if (key < n->key){
        n->left = insertion(n->left, key);
        n->left->parent = n;
    }
    else{
        n->right = insertion(n->right, key);
        n->right->parent = n;
    }

    /*if(key == n->key)
        n->key = key;
        //n->val = val;
    else if (key < n->key){
        n->left = insertion(n->left, key /*val*);
        n->left->parent = n;
    }
    else{
        n->right = insertion(n->right, key /*val*);
        n->right->parent = n; 
    }*/

    if(n->right->color == true)
        n = rotateLeft(n);

    if((n->left->color == true) && (n->left->left->color == true))
        n = rotateRight(n);
    
    if((n->left->color == true) && (n->right->color == true))
        colorFlip(n);

    return n;
}

void RBTree::deleteMin(){
    root = deleteMin(root);
    root->color = false;
}

Node* RBTree::deleteMin(Node* n){
    if(n->left == NULL)
        return NULL;
    if((n->left->color == false)&&(n->left->left->color == false))
        n = moveRedLeft(n);
    
    n->left = deleteMin(n->left);
    return fixUp(n);
}

void RBTree::deletion(int key){
    root = deletion(root, key);
    root->color = false;
}

/*Node BinTree::*deleteNode(Node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct Node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct Node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}*/


Node* RBTree::deletion(Node* n, int key){
    if(n == NULL)
        return n;
    if(key < n->key){
        if((n->left->color == false)&&(n->left->left->color == false))
            n = moveRedLeft(n);
        n->left = deletion(n->left, key);
    }
    else{
        if(n->left->color == true)
            n = rotateRight(n);
        if((key == n->key) && (n->right == NULL))
            return NULL;
        if((n->left->color == false)&&(n->right->left->color == false))
            n = moveRedRight(n);
        if(key == n->key){
            n->val = get(n->right, min(n->right)->key);
            n->key = min(n->right)->key;
            n->right = deleteMin(n->right);
        }
        else
            n->right = deletion(n->right, key);
    }
    return fixUp(n);
}

int RBTree::getNode(int i){
    return nodes.at(i);
}

int RBTree::get(Node* n, int key){
    while(n != NULL){
        if(key == n->key)
            return n->key;
            //return n->val;
        else if(key < n->key)
            n = n->left;
        else if(key > n->key)
            n = n->right;
    }
    return NULL;
}

int RBTree::get(int key){
    Node* x = root;
    while(x != NULL){
        if(key == x->key)
            return x->key;
            //return x->val;
        else if(key < x->key)
            x = x->left;
        else if(key > x->key)
            x = x->right;
    }
    return NULL;
}

Node* RBTree::min(Node* n) {
		while (n->left != NULL) {
			n = n->left;
		}
		return n;
	}

Node* RBTree::moveRedLeft(Node* n){
    colorFlip(n);
    if(n->right->left->color == true){
        n->right = rotateRight(n->right);
        n = rotateLeft(n);
        colorFlip(n);
    }
    return n;
}

Node* RBTree::moveRedRight(Node* n){
    colorFlip(n);
    if(n->left->left->color == true){
        n = rotateRight(n);
        colorFlip(n);
    }
    return n;
}

Node* RBTree::rotateRight(Node* n){
    Node *x = n->left;
    n->left = x->right;
    x->right = n;
    x->color = x->right->color;
    //Red = true
    x->right->color = true;
}

Node* RBTree::rotateLeft(Node* n){
    Node *x = n->right;
    n->right = x->left;
    x->left = n;
    x->color = x->left->color;
    //Red = true
    x->left->color = true;
}

Node* RBTree::colorFlip(Node* n){
    n->color = !n->color;
    n->right->color = !n->right->color;
    n->left->color = !n->left->color;
};

//BinTree
// Return a new node if the tree is empty

/*void BinTree::inorder(Node *root){
    if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    std::cout << root->key << " -> ";

    // Traverse right
    inorder(root->right);
  }
}*/

/*Node *insert(Node *node, int key){
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}*/

/*Node BinTree::*minValueNode(Node *node){
    struct Node *current = node;

  // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

  return current;
}*/

