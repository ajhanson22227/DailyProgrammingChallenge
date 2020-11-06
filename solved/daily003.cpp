/*
    Given the root to a binary tree, implement serialize(root), 
    which serializes the tree into a string, and deserialize(s), 
    which deserializes the string back into the tree.
*/

#include <iostream>
#include <string>

class Node{
    public:
        Node();
        Node(std::string val);
        Node(std::string val, Node*, Node*);

        void details(int tabNum);

        void insertLeft(Node *node){
            left = node;
        }

        std::string serialize();

        std::string value;
        Node* left;
        Node* right;

};

Node::Node(){
    value = "root";
    left = nullptr;
    right = nullptr;
}
Node::Node(std::string val){
    value= val;
    left = nullptr;
    right=nullptr;
}
Node::Node(std::string val, Node* lnode, Node* rnode){
    value = val;
    left = lnode;
    right = rnode;
}

void Node::details(int tabNum){
    //std::cout << "Value: " << this->value << "\nLeft: " << this->left << "\nRight: " <<this->right << std::endl;
    for (int i = 0; i < tabNum; i++) {
        std::cout << "\t";
    }
    if (this == nullptr){
        std::cout << "Empty\n";
        return;
    }
    
    std::cout << "Value: " << this->value << std::endl;
    this->left->details(tabNum+1);
    this->right->details(tabNum+1);
}

std::string Node::serialize(){
    if (this == nullptr) return "%/";
    std::string serialString = "";
    serialString += this->value + "/" + this->left->serialize() + this->right->serialize();
    return serialString;
}


int main(){
    Node *root = new Node("root", new Node("left", new Node("left.left"), nullptr), new Node("right"));
    root->details(0);
    std::string rootSerialized = root->serialize();
    std::cout << rootSerialized << std::endl;

    return 0;
}