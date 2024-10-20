#include<iostream> /*Separate Chaining*/
using namespace std;
class Node{
    public:
        int key;
        string value;
        Node *next;
        Node(int key , string value){
            this->key = key;
            this->value = value;
            this->next = NULL;
        }
};
class Linkedlist{
    public:
        Node* head;
        Node* last;
        Linkedlist(){
            head = new Node(-1,"-");
        }
        void insertToLast(int key, string value){
            Node* newNode = new Node(key,value);
            if(head->key == -1 && head->value == "-"){
                head = newNode;
                last = newNode;
            }
            else{
                last->next = newNode;
                last = newNode;
            }
        }
        void display(){
            for (Node* ptr = head ; ptr != NULL; ptr = ptr->next)
            {
                cout << "("<<ptr->key <<","<<ptr->value<<")" <<" ";
            }cout << endl;
            
        }
        string search(int key);
};
string Linkedlist::search(int key){
    Node* ptr = head;
    while(ptr){
        if(ptr->key == key){
            return ptr->value;
        }
    ptr = ptr->next;
    }return "-";
}


int hashFunciton(int n){
    return n%17;
}

int main(){
    Linkedlist hashTable[17];
    char s;
    int key;
    string value;

    do{
        cin >>s;
        switch (s){
        case 'a':
            cin >>key>>value; 
            hashTable[hashFunciton(key)].insertToLast(key,value);
            break;
        case 'p':
            for (int i = 0; i < 17; i++){
                hashTable[i].display();
            }
            break;
        case 's':
            cin >>key;
            cout<< hashTable[hashFunciton(key)].search(key) <<endl;
        case 'e':
            break;
        }

    }while(s != 'e');
  
    return 0;
}