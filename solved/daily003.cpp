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

        void details(int);

        void insertLeft(Node* node){
            left = node;
        }

        std::string serialize();
        Node* deserialize(std::string, int &index);

        std::string value;
        Node* left;
        Node* right;

};

Node::Node(){
    value = "";
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
    if (this == nullptr) return "!/";
    std::string serialString = "";
    serialString += this->value + "/" + this->left->serialize() + this->right->serialize();
    return serialString;
}

Node* Node::deserialize(std::string serializedString, int &index){
    std::string val = "";
    Node* tempNode = new Node();
    for (int i = index; i < serializedString.size(); i++){
        if (serializedString[i] == '!'){
            index += 1;
            return nullptr;
        }
        else if (serializedString[i] == '/'){
            tempNode->value = val;
            index = i + 1;
            break;
        }
        else{
            val += serializedString[i];
        }
    }
    tempNode->left = this->deserialize(serializedString, index);
    index+=1;
    tempNode->right = this->deserialize(serializedString, index);
    return tempNode;
}


int main(){
    Node *root = new Node("root", new Node("left", new Node("left.left"), nullptr), new Node("right"));
    root->details(0);
    std::string rootSerialized = root->serialize();
    std::cout << rootSerialized << std::endl;

    int ind = 0;
    Node *newNode = root->deserialize(rootSerialized, ind);
    newNode->details(0);
    return 0;
}