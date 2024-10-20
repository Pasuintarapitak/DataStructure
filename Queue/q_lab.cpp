#include<iostream>
using namespace std;
class Queue_lab{ // LAB + Circular
    public:
        int front;
        int rear;
        int size;
        int *data;
        int count;
        Queue_lab(){}
        Queue_lab(int size){
            front = 1;
            rear = 1;
            count = 0; // นับขนาด
            this->size = size+1;
            data = new int[size+1]{0};
        }
        bool is_full(){
            return rear % size +1 == front;
        }
        bool is_empty(){
            return front == rear;
        }
        void enqueue(int number){
            if(is_full()){
                cout<<"FULL"<<endl;
            }
            else{
                data[rear] = number;
                rear = rear%size + 1;
                count++;
            }
        }
        int dequeue(){
            int temp_data = -1;
            if(is_empty()){
                cout<<"EMPTY"<<endl;
                return -1;
            }
            else{
                temp_data = data[front];
                front = front%size +1;
                count--;
                return temp_data;
            }
        }
        void displayALL(){
            for (int i = front; i < rear; i++)
            {
                cout<< data[i] << " "<<flush;
            }cout<<endl;
        }
        void displayFL(){
            cout<<data[front] <<" " <<data[rear-1]<<endl;
        }
        void queueSize(){
            cout<<count<<endl;
        }

};
int main(){
    int n = 5;
    int number;
    char s;
    Queue_lab q(n);
    do{
        cin >>s;
        switch(s){
            case 'e': cin>>number; q.enqueue(number);break;
            case 'd': cout<<q.dequeue()<<endl;break;
            case 'p': q.displayALL();break;
            case 'n': q.queueSize();break;
            case 's': q.displayFL();break;
            case 'x': break;      

        }

    }while(s != 'x');
    return 0;
}
