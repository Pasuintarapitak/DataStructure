#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph{
    public:
        int edges[100][100];
        int s_v;
        Graph(int n){
            s_v = n;
            for (int i = 0; i < s_v; i++)
            {
                for (int j = 0; j < s_v; j++)
                {
                    edges[i][j] = 0;
                }
                
            }
            
        }
        void addEdge(int s , int d , int n){
            edges[s][d] = n;
        }

        void bft(int v){
            bool visited_bft[100];
            for(int i = 0 ; i < 100 ; i++){
                visited_bft[i] = 0;
            }
            visited_bft[v] = 1;
            queue<int> q;
            q.push(v);
            while(!q.empty()){
                v = q.front();
                cout << v << " ";
                q.pop();
                for(int d = 0 ; d < s_v ; d++){
                    if(!visited_bft[d] && edges[v][d] > 0){
                        visited_bft[d] = 1;
                        q.push(d);
                    }
                }

            }
            cout << endl;

        }
        bool visited_dft[100];
        void sub_dft(int v){
            cout << v << " ";
            visited_dft[v] = true;
            for (int i = 0; i < s_v; i++)
            {
                if(!visited_dft[i] && edges[i][v] > 0){
                    sub_dft(v);
                }
            }
            
        }
        void dft(int n){
            for (int i = 0; i < 100; i++)
            {   
                visited_dft[i] = false;    
            }
            sub_dft(n);
            cout<<endl;
            
        }

};
int main(){
    int n = 5;
    Graph g(n);
    // g.addEdge()
    return 0;
}