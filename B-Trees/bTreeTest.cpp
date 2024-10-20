#include<iostream>
#include<queue>
using namespace std;

// template <typename Type>
class Node{
    public:
        int value;
        Node *left;
        Node *right;
        Node(int value){
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};
class Tree{
    public:
        Node *root;
        int size = -1;
        Tree(){
            root = nullptr;
        }
        void insert(int data);
       
        int sizeTree();
        int sizeTree(Node* node);
        
        int heightTree();
        int heightTree(Node* node);

        void clearTree();
        void clearTree(Node* node);

        void Breadthfirst(); // Breadthfirst == Level Order

        void Preorder();
        void Preorder(Node* node);
        
        void Inorder();
        void Inorder(Node* node);

        void Postorder();
        void Postorder(Node* node);

        bool searchNode(int value);

        void deleteNode(int value);
        Node* deleleNode(Node* root , int value);
        Node* findMin(Node* root);
};
// Insert
void Tree::insert(int data){
    if(root == nullptr && size == -1){
        root = new Node(data);
        size++;    
    }
    else{
        Node *ptr = root; //ตัวเลื่อนตำแหน่ง
        //data มากกว่า root
        while(true){
            if(data >= ptr->value){
                //ด้านขวาเป็น null
                if(ptr->right == nullptr){
                    ptr->right = new Node(data);
                    size++;
                    return;
                }
                else{
                    ptr = ptr->right;
                }   
            }

            //data น้อยกว่า root
            else{
                if(ptr->left == nullptr){
                    ptr->left = new Node(data);
                    size++;
                    return;
                }
                else{
                    ptr = ptr->left;
                }
            }
        }
    }
}

//Delete Node (ยากสุด)
void Tree::deleteNode(int value){
    this->root = deleleNode(root,value);
    return;
}
Node* Tree::deleleNode(Node* root , int value){
    if(root == nullptr){
        return root;
    }
    else{
        if(value < root->value){
            root->left = deleleNode(root->left,value);
        }
        else if (value > root->value){
            root->right = deleleNode(root->right,value);
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
            else{
                Node* temp = findMin(root->right);
                root->value = temp->value;
                root->right = deleleNode(root->right,temp->value);
            }
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
//Size
int Tree::sizeTree(){
    return sizeTree(root);
}
int Tree::sizeTree(Node* node){
    if(node == nullptr){
        return 0;
    }
    else{
        return 1 + sizeTree(node->left) + sizeTree(node->right);
    }
}

//Height
int Tree:: heightTree(){
    return heightTree(root);
}
int Tree:: heightTree(Node* node){
        
    if(node == nullptr){
        return -1;
    }
        
    else{
        int leftNode = heightTree(node->left);
        int rightNode = heightTree(node->right);
        return 1+max(leftNode,rightNode); // 1 + (เทียบด้านไหนสูงกว่า)
    }
}

//Clear Tree
void Tree :: clearTree(){
    clearTree(root);
    root = nullptr;
    return;
}
void Tree:: clearTree(Node *node){
    if(node == nullptr){
        return;
    }
    else{
        clearTree(node->left);
        clearTree(node->right);
        delete node;

    }
}


// Breadth First Traversal
void Tree::Breadthfirst(){
    if(root == nullptr){
        cout<< "Empty Tree"<<endl;
        return;
    }
    else{
        Node *ptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int level_size = q.size();
            for(int i = 0 ; i < level_size ; i++){
                ptr = q.front();
                cout << ptr->value << ",";
                q.pop();
                if(ptr->left != nullptr){
                    q.push(ptr->left);
                }
                if(ptr->right != nullptr){
                    q.push(ptr->right);
                }
            }
            cout << "|" ;
        }
        cout <<endl;
    }
}

//Preorder
void Tree::Preorder(){
    Preorder(root);
    cout << endl;
    return;
}
void Tree::Preorder(Node *node){
    if(node == nullptr){
        return;
    }
    else{
        cout << node->value <<",";
        Preorder(node->left);
        Preorder(node->right);
    }
   
}

//Inorder
void Tree::Inorder(){
    Inorder(root);
    cout << endl;
    return;
}
void Tree::Inorder(Node *node){
    if(node == nullptr){
        return;
    }
    else{
        Inorder(node->left);
        cout << node->value<<",";
        Inorder(node->right);
    }
}

//Postorder
void Tree::Postorder(){
    Postorder(root);
    cout << endl;
    return;
    }
void Tree::Postorder(Node* node){
    if(node == nullptr){
        return;
    }
    else{
        Postorder(node->left);
        Postorder(node->right);
        cout<<node->value<<",";
    }
}

//Search Node
bool Tree::searchNode(int value){
    if(root == nullptr){
        return false;
    }
    else{
        Node *ptr = root;
        while(ptr != nullptr){
       
            if(ptr->value == value){
                return true;
            }
            else if(ptr->value <= value){
                ptr = ptr->right;
            }
            else{
                ptr = ptr->left;
            }
        }
        return false;
    }
}
int main(){
    Tree t;
    char s;
    int data;
    do{
        cin >> s;
        switch(s){
            case 'a':
                cin >> data;
                t.insert(data);
                break;
            case 'd':
                cin >> data;
                t.deleteNode(data);
                break;
            case 'c':
                t.clearTree();
                cout << "Clear"<<endl;
                break;
            case 's':
                cout << "Size of tree: " << t.sizeTree() <<endl;
                break;
            case 'h':
                cout << "Height of tree: " << t.heightTree() <<endl;
                break;
            case 'f':
            cin >> data;
                cout << "Value is found : " << t.searchNode(data) <<endl;
                break; 
            case 'b':
                //Breadth first
                t.Breadthfirst();
                break;
            case 'i':
                //In Order
                t.Inorder();
                break;
            case 'p':
                //PreOrder
                t.Preorder();
                break;
            case 't':
                //PostOrder
                t.Postorder();
                break;
            case 'x':
                break;
        }
    }while(s != 'x');

    return 0 ;
}


// a 10         
// a 7
// a 13
// a 2
// a 9
// a 20
// a 11
// b