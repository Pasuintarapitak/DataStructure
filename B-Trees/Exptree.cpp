#include<iostream>
#include<cctype>
#include<string>
#include<stack>
using namespace std;
class Node{
    public:
        char value;
        Node* left;
        Node* right;
        Node(char value){
            this->value  = value;
            left = nullptr;
            right = nullptr;
        }
};
bool isOperator(char ch){
    return ch =='+' || ch == '-' || ch == '*' || ch == '/';
}
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; 
}
Node* expTree(const string& infix){
    stack<Node*> number;
    stack<char> operators;
    for(char ch:infix){
        if(isspace(ch)){
            continue; //whitespace
        }
        if(isalnum(ch)){
            number.push(new Node(ch));//ch == number
        }
        if(isOperator(ch)){
            while(!operators.empty() && precedence(operators.top()) >= precedence(ch)){
                char op = operators.top();
                operators.pop();

                Node* t1 = number.top();
                number.pop();
                Node* t2 = number.top();
                number.pop();

                Node* opNode = new Node(ch);
                opNode->left = t2;
                opNode->right = t1;

                number.push(opNode);
            }
            operators.push(ch);
        }
    }

    while(!operators.empty()){
        Node* t1 = number.top(); number.pop();
        Node* t2 = number.top(); number.pop();
        Node* opNode = new Node(operators.top());
        operators.pop();
        opNode->left = t2;
        opNode->right = t1;
        number.push(opNode);
    }    
    return number.top();
}
void postOrder(Node* root){
    if(root == nullptr){
        return;
    }
    else{
        postOrder(root->left);
        postOrder(root->right);
        cout << root->value <<" ";
    }
}
int main(){
    string s;
    getline(cin,s);
    Node* tree = expTree(s);
    postOrder(tree);

    return 0;
}