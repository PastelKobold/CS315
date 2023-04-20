#include <iostream>
#include"Nodes.cpp"

int main() {
    RBTree mytree;
    mytree.fileRead();
    struct Node *root = NULL;
    for(int i = 0; i < mytree.getsize(); i++){
        root = insert(root, mytree.getNode(i));

    }

    std::cout << "Inorder traversal: ";
    inorder(root);

    std::cout << std::endl;

    std::cout << "Height: " << getHeight(root) << std::endl;

    //Reading again
    mytree.fileRead();

    for(int i = 0; i < mytree.getsize(); i++){
        root = deleteNode(root, mytree.getNode(i));
    }
    //root = deleteNode(root, mytree.getNode(5));
    //root = deleteNode(root, mytree.getNode(10));
    std::cout << "Inorder traversal: ";
    inorder(root);
    std::cout << std::endl;
    
    std::cout << "Height: " << getHeight(root) << std::endl;
    //Sadly doesn't work :()
    std::cout << "Now for RBTree, which file would you like" << std::endl;
    mytree.fileRead();
    for(int i = 0; i < mytree.getsize(); i++){
        mytree.insertion(mytree.getNode(i));
        std::cout << "Test";
    }
    std::cout<< "Made it here" << std::endl;
    mytree.inorderTraversal(mytree.getRoot());
    return 0;
};

/*RBTree mytree;
    Node* n;
    mytree.fileRead();
    std::cout << mytree.getsize() << std::endl;
    for(int i = 0; i < mytree.getsize(); i++){
        mytree.insertion(mytree.getNode(i));
        std::cout << "Test";
    }
    std::cout<< "Made it here" << std::endl;
    mytree.inorderTraversal(mytree.getRoot());
    return 0;*/