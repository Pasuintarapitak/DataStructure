#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
	int edges[100][100];
	int s_v;
	
	Graph(int n) {
		s_v = n;
		
		for (int i = 0; i < s_v; i++) {
			for (int j = 0; j < s_v; j++) {
				edges[i][j] = 0;
			}
		}
	}
	
	void add_edge(int x, int y, int w) {
		edges[x][y] = w;
	}
	
	void bft(int start) {
		bool visited_bft[100];
		
		for (int i = 0; i < 100; i++) {
			visited_bft[i] = 0;
		}
		visited_bft[start] = 1;
		vector<int> q;
		q.push_back(start);
		while (!q.empty()) {
			start = q.front();
			cout << start << " ";
			q.erase(q.begin());
			for (int y = 0; y < s_v; y++) {
				if (visited_bft[y] == 0 && edges[start][y] > 0) {
					visited_bft[y] = 1;
					q.push_back(y);
				}
			}
		}
		cout << endl;
	}
	
	bool visited_dft[100];
	
	void sub_dft(int start) {
		cout << start << " ";
		visited_dft[start] = 1;
		for (int y = 0; y < s_v; y++) {
			if (visited_dft[y] == 0 && edges[start][y] > 0) {
				sub_dft(y);
			}
		}
	}
	
	void dft(int start) {
		for(int i = 0; i < 100; i++) {
			visited_dft[i] = 0;
		}
		sub_dft(start);
		cout << endl;
	}
	
	void sub_graph() {
		int num_subgraph = 1;
		for(int i = 0; i < 100; i++) {
			visited_dft[i] = 0;
		}
		for (int y = 0; y < s_v; y++) {
			if (visited_dft[y] == 0) {
				cout << "\nsub graph = " << num_subgraph << " : ";
				sub_dft(y);
				num_subgraph = num_subgraph + 1;
			}
		}
	}
};

int main() {
	int n;
	char cmd;
	
	cin >> n;
	Graph g(n);
	
	int x, y, w;
	bool adding = true;
	while (adding) {
		cin >> cmd;
		switch (cmd) {
			case 'e':
				cin >> x >> y >> w;
				g.add_edge(x, y, w);
				break;
			case 's':
				adding = false;
				break;
			case 'q':
				return 0;
		}
	}
	
	int start;
	while (true) {
		cin >> cmd;
		switch (cmd) {
			case 'd':
				cin >> start;
				g.dft(start);
				break;
			case 'b':
				cin >> start;
				g.bft(start);
				break;
			case 'q':
				return 0;
		}
	}
}