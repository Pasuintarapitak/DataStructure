#include<iostream>
using namespace std;

class Stack{
    public:
        char arr[100];
        int top;
        Stack(){
            top = -1;
        }
        void push(char bracket){
            if(top < 99){
                if(bracket == '('){
                    arr[++top] = '(';

                }
                else if(bracket == ')'){
                    if(arr[top] == '(' && top!=-1){
                        top--;
                    }
                    else{
                        arr[++top] = ')';
                    }
                }
            }
        }
     
        void display(){
            int i = 0;
            while(i <= top){
                cout<<arr[i++]<<" ";
            }cout<< endl;
            
        }
};


int main(){
    Stack s1;
    char test[100];
    int n = 0;
    cin >>test;
    while(test[n] != '\0'){
        s1.push(test[n]);

        n++;
    }
    if(s1.top > -1){
        cout<<"Error";
    }
    else{
        cout<<"Pass";
    }
    cout<< endl;
    s1.display();
    return 0;
}