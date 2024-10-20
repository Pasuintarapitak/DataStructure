#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
        Node *left;
        Node *right;
        int data;
    Node(int data){
        left = nullptr;
        right =nullptr;
        this->data = data;
    }
};
class bTree{
    public:
        Node *root;
        bTree(){
            root = nullptr;
        }
        void addNode(int data);
        void insert(int value); //Recursion add
        void insert(int value, Node* node); //Recursion add
        void levelOrder();   
};
void bTree::addNode(int data){
    Node *newNode = new Node(data);
    Node *ptr = root; //point when adding
    if(root == nullptr){
        root = newNode;
        return;
    }
    else{
        while(true){
            if(data < ptr->data){
                if(ptr->left == nullptr){
                    ptr->left = newNode;
                    return;
                }
                else{
                    ptr = ptr->left;   
                }
            }
            else{
                if(ptr->right == nullptr){
                    ptr->right = newNode;
                    return;
                }
                else{
                    ptr = ptr->right;
                }
            }
        }

    }
}
void bTree::levelOrder(){
    if(root == nullptr){
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node *node = q.front();
        q.pop();
        cout << node->data << endl;
        if(node->left){
            q.push(node->left);
        }
        if(node->right){
            q.push(node->right);
        }
    } 
}

void bTree::insert(int value){
    if(!root){
        root = new Node(value);
        root->left = nullptr;
        root->right = nullptr;
    }
    else{
        this->insert(value,root);
    }
}
void bTree::insert(int value , Node* node){
    if(value < node->data){
        if(!node->left){
            node->left = new Node(value);
            node->left->left = nullptr;
            node->left->right = nullptr;
        }
        else{
            this->insert(value , node->left);
        }
    }
    else if(value > node->data){
        if(!node->right){
            node->right = new Node(value);
            node->right->left = nullptr;
            node->right->right = nullptr;
        }
        else{
            this->insert(value , node->right);
        }
    }
}

int main(){
    bTree tree;
    // tree.addNode(1);
    // tree.addNode(2);
    // tree.addNode(3);
    // tree.addNode(4);
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.levelOrder();
}