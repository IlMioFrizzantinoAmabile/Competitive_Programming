/* PROBLEM
 * Given an adjacency matrix representation of a graph g having 0 based index the task is to complete the function isBipartite
 * which returns true if the graph is a bipartite graph else returns false.
 * Input:
 * The first line of input contains an integer T denoting the no of test cases. Then T test cases follow.
 * Each test case contains an integer v denoting the no of vertices of the graph.
 * Then in the next line are v*v space separated values of the adjacency matrix representation of the graph g.
 * Output:
 * For each test case in a new line output will be 1 if the graph is bipartite else 0.
 * SOURCE: https://practice.geeksforgeeks.org/problems/bipartite-graph/1
 *
 * SOLUTION
 * Per un grafo essere bipartito equivale all'esistenza di una 2-colorazione.
 * L'algoritmo verifica quindi che questa esista o meno tramite una DFS.
 * COMPLEXITY: O(n^2)  
 * (volendo O(m) se il grafo venisse salvato come una matrice sparsa)
 */

#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
bool isBipartite(int G[][MAX],int V);
int main()
{
    int t;
	cin>>t;
	int g[MAX][MAX];
	while(t--)
	{
		memset(g,0,sizeof (g));
		int n;
		cin>>n;
	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>g[i][j];
			}
		}
		
		cout<<isBipartite(g,n)<<endl;
	}
	return 0;
}

/*Please note that it's Function problem i.e.
the task is to write the solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.*/

bool isBipartite(int G[][MAX],int V) {
	vector<int> color(V,0);
	queue<int> Q;
	for (int start=0;start<V;start++) if (!color[start]) {
		color[start]=1;
		Q.push(start);
		while (!Q.empty()) {
			int node=Q.front();
			Q.pop();
			for (int j=0;j<V;j++) if (G[node][j]) {
				if (!color[j]) Q.push(j);
				if (color[node]==color[j]) return 0;
				color[j] = 3-color[node];
			}
		}
	}
	return 1;
}
