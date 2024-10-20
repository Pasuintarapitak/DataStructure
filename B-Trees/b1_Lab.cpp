#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int data){
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};
class Tree{
    public:
        Node *root;
        int size = 0;
        Tree(){
            root = nullptr;
        }
        //insert
        void insert(int data);//Normal
      
        //size
        void Size(); // CHR Algolithm
        int sizeTree();//Recursive by team
        int sizeTree(Node* node);
        //height
        int height();
        int height(Node* node);
        //clear
        void clear();
        void clear(Node* node);
        //delete
        void deleteNode(int data);
        Node* deleteNode(Node* root , int data);
        Node* findMin(Node* root);
        Node* findMax(Node* root);
        //Search Breath first , Pre Order ,In Order , Post Order
        void Breadthfirst();

        void Preorder();
        void Preorder(Node* node);

        void Inorder();
        void Inorder(Node* node);

        void Postorder();
        void Postorder(Node* node);
       
       //Delete 

};

void Tree::insert(int data){
    if(root == nullptr){
        root = new Node(data);
        size++;
        return;
    }
    else{
        Node* ptr = root;
        while(true){
            if(data < ptr->data){
                if(ptr->left == nullptr){
                    ptr->left = new Node(data);size++;
                    return;
                }
                else{
                    ptr = ptr->left;
                }
            }
            else if(data > ptr->data){
                if(ptr->right == nullptr){
                    ptr->right = new Node(data);size++;
                    return;
                }
                else{
                    ptr = ptr->right;
                }
            }
        }
    }
}

void Tree::Breadthfirst(){
    if(root == nullptr){
        return;
    }
    else{
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int levelSize = q.size();
            for(int i = 0 ; i < levelSize ; i++){
                Node* ptr = q.front();
                
                cout << ptr->data <<" ";
                q.pop();
                if(ptr->left != nullptr){
                    q.push(ptr->left);
                }
                if(ptr->right != nullptr){
                    q.push(ptr->right);
                }
            }

        }
        cout << endl;
        return;
    }
}

void Tree::Preorder(){
    return Preorder(root);
}
void Tree::Preorder(Node* node){
    if(node == nullptr){
        return;
    }
    else{
        cout << node->data<< " ";
        this->Preorder(node->left);
        this->Preorder(node->right);
    }
}

void Tree::Inorder(){
    return this->Inorder(root);
}
void Tree::Inorder(Node* node){
    if(node == nullptr){
        return;
    }
    else{
        Inorder(node->left);
        cout << node->data <<" ";
        Inorder(node->right);
    }
}

void Tree::Postorder(){
    return this->Postorder(root);
}
void Tree::Postorder(Node* node){
    if(node == nullptr){
        return;
    }
    else{
        Postorder(node->left);
        Postorder(node->right);
        cout<<node->data<<" ";
    }
}

int Tree::sizeTree(){
    return this->sizeTree(root);
}
int Tree::sizeTree(Node* node){
    if(node == nullptr){
        return 0;
    }
    return 1+sizeTree(node->left)+sizeTree(node->right);
}

int Tree::height(){
    return this->height(root);
}
int Tree::height(Node* node){
    if(node == nullptr){
        return -1;
    }
    else{
        int left = height(node->left);
        int right = height(node->right);
        return 1+max(left,right);
    }
}

void Tree::clear(){
    clear(root);
    root = nullptr;
    return;
}
void Tree::clear(Node* node){
    if(node == nullptr){
        return;
    }
    else{
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

void Tree::deleteNode(int data){
    this->root = deleteNode(root,data);
    return;
}
Node* Tree::deleteNode(Node* root , int data){
    if(root == nullptr){
        return root;
    }
    else{
        if(data < root->data){
            root->left = deleteNode(root->left,data);
        }
        else if(data > root->data){
            root->right = deleteNode(root->right,data);
        }
        else{
            if(root->left == nullptr){
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == nullptr){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // Node* temp = findMin(root->right);
            // root->data = temp->data;
            // root->right = deleteNode(root->right,data);
            Node* temp = findMax(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left,temp->data);
        }
        return root;
    }
}
Node* Tree::findMin(Node* root){
    Node* ptr = root;
    while(ptr != nullptr && ptr->left != nullptr){
        ptr = ptr->left;
    }
    return ptr;
}
Node* Tree::findMax(Node *root){
    Node* ptr = root;
    while(ptr != nullptr && ptr->right !=nullptr){
        ptr = ptr->right;
    }
    return ptr;
}

int main(){
    Tree t;
    t.insert(6);
    t.insert(2);
    t.insert(9);
    t.insert(1);
    t.insert(5);
    t.insert(8);
    t.insert(4);
    t.insert(7);
    t.deleteNode(5);
    t.Breadthfirst();
    t.Preorder();cout<<endl;
    t.Inorder();cout<<endl;
    t.Postorder();cout<<endl;
    // cout << t.sizeTree()<<endl;
    // cout <<t.size << endl;
    // cout << t.height()<<endl;
    
    // t.clear();
  
    return 0;
}