#include <bits/stdc++.h>
using namespace std;

int minKey(int key[], bool mstSet[], int V) {
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;
	return min_index;
}

void printMST(int parent[], vector<vector<int> > graph, int V) {
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t"
			<< graph[i][parent[i]] << " \n";
}

void primMST(vector<vector<int> > graph, int V){
	int parent[V];

	int key[V];

	bool mstSet[V];

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;
	parent[0] = -1; 

	for (int count = 0; count < V - 1; count++) {
		int u = minKey(key, mstSet, V);

		mstSet[u] = true;

		for (int v = 0; v < V; v++)

			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	printMST(parent, graph, V);
}

int main() {
  int V; cin >> V;
	vector<vector<int> > graph(V, vector<int>(V));

  cout << "Enter the adjacency matrix: \n";
  for(int i=0; i<V; i++) {
    for(int j=0; j<V; j++) {
      cin >> graph[i][j];
    }
  }

	primMST(graph, V);

	return 0;
}
