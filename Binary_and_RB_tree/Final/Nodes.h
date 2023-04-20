#ifndef NODE_H
#define NODE_H
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <queue>
#include <vector>
#include<iostream>

struct Node{
    bool color = true; //Red = true Black = false
    int key;
    int val;
    int height = 0;
    Node *left, *right, *parent;
    Node(int key){
        this->key =key;
        left = right = parent = NULL;
        this->color = true; //Red
        this->val = val;
    }
};

struct Node *newNodeRB(int item /*int val*/) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->key = item;
  //temp->val = val;
  temp->color = true;
  temp->left = temp->right = NULL;
  return temp;
};

Node *newNode(int item) {
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
};

int getHeight(struct Node *root){
  return root->height;
}

// Inorder Traversal
void inorder(struct Node *root) {
  if (root != NULL) {
    // Traverse left
    root->height = root->height + 1;
    inorder(root->left);

    // Traverse root
    std::cout << root->key << " -> ";

    // Traverse right
    inorder(root->right);
  }
}

// Insert a node
struct Node *insert(struct Node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Find the inorder successor
struct Node *minValueNode(struct Node *node) {
  struct Node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct Node *deleteNode(struct Node *root, int key) {
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
}

class RBTree{
    public:
        RBTree() { root = NULL; }
        void fileRead();
		void inorderTraversal(Node *root);
        int search(const int key);
        Node* insertion(Node* n, int key /*int val*/);
        void insertion(int key /*int val*/);
        void deletion(int key);
        Node* deletion(Node* n, int key);
        void deleteMin();
        Node* deleteMin(Node* n);
        Node* moveRedLeft(Node* n);
        Node* moveRedRight(Node* n);
        Node* min(Node* n);
        int get(int key);
        int get(Node* n, int key);
        Node* fixUp(Node* n);
        int getsize();
        int getNode(int i);
        Node* getRoot();
    protected:
    Node* rotateRight(Node* n);
    Node* rotateLeft(Node* n);
    Node* colorFlip(Node* n);
    private:
    int size;
    Node *root = NULL;
    std::vector<int> nodes;
};

/*class BinTree{
    public:
        void inorder(Node *root);
        Node *insert(Node *node, int key);
        Node *minValueNode(Node *node);
        Node *deleteNode(Node *root, int key);
    private:
};*/
#endif