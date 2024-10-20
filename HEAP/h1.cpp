// Max Heap
#include<iostream>
using namespace std;
#define MAX 100
class Heap{
    public:
        int arr[MAX];
        int size = 0;  

        // void add(int n);

        void insert(int n);
        void heapify(int root);
        int Delete();
        void print();

};
void Heap::insert(int n){
    if(size >= MAX){
        return;
    }

    //add to array
    arr[size] = n;
    size++;

    //Check Parent > Child
    int index = size - 1;
    while(index > 0 && arr[index] > arr[(index-1)/2]){
        swap(arr[index],arr[(index-1)/2]);
        index = (index-1)/2;
    }

}
int Heap::Delete(){
    if(size <= 0){
        return -1;
    }
    else if(size == 1){
        size--;
        return arr[size];
    }
    else{
        int root = arr[0];
        int index = size - 1;
        swap(arr[index],arr[0]);
        size--;

        heapify(0);
        return root;
    }
}
void Heap::heapify(int index){
    int root = index;
    int left = 2*index+1;
    int right = 2*index+2;
    if(left < size && arr[left] > arr[root]){
        root = left;
    }
    if(right < size && arr[right] > arr[root]){
        root = right;
    }
    //Recursive แบบเทพๆ
    if(root != index){
        swap(arr[root],arr[index]);
        heapify(root);
    }
}
void Heap::print(){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] <<" ";
    }cout <<endl;
    
}
int main(){
    Heap h;
    char s;
    int n;
    do{
        cin >> s;
        switch (s)
        {
        case 'a':
            cin >> n;
            h.insert(n);
            break;
        case 'd':
            h.Delete();//Delete root node
            break;
        case 'p':
            h.print();
            break;
        case 'e':
            break;
    
        }
    }while(s != 'e');

    return 0;
}