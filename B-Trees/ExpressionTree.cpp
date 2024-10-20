#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

// Node class for expression tree
class Node {
public:
    char value;
    Node* left, * right;

    Node(char value) {
        this->value = value;
        this->left = this->right = nullptr;
    }
};

// Function to check if the character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to construct expression tree from infix expression
Node* constructTree(const string& infix) {
    stack<Node*> nodes; // Stack to hold tree nodes
    stack<char> operators; // Stack to hold operators

    for (char ch : infix) {
        // Skip spaces
        if (ch == ' ') continue;

        // If the character is an operand, create a new node and push it onto the stack
        if (isalnum(ch)) {
            nodes.push(new Node(ch));
        }
        // If the character is an operator
        else if (isOperator(ch)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                // Pop the operator and top two nodes
                char op = operators.top();
                operators.pop();
                Node* t1 = nodes.top(); nodes.pop();
                Node* t2 = nodes.top(); nodes.pop();

                // Create a new node for the operator
                Node* opNode = new Node(op);
                opNode->left = t2; // Left child
                opNode->right = t1; // Right child

                // Push the new node onto the stack
                nodes.push(opNode);
            }
            // Push the current operator onto the stack
            operators.push(ch);
        }
    }

    // Pop all the operators and remaining nodes to create the expression tree
    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();
        Node* t1 = nodes.top(); nodes.pop();
        Node* t2 = nodes.top(); nodes.pop();

        Node* opNode = new Node(op);
        opNode->left = t2;
        opNode->right = t1;

        nodes.push(opNode);
    }

    // The last node remaining in the stack is the root of the expression tree
    return nodes.top();
}

// Function for postorder traversal of the expression tree
void postorderTraversal(Node* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->value << " ";
    }
}

int main() {
    string infix = "3 + 5 * ( 2 - 4 )"; // Example infix expression
    Node* expTree = constructTree(infix);

    cout << "Postorder traversal of the expression tree: ";
    postorderTraversal(expTree);
    cout << endl;

    return 0;
}
