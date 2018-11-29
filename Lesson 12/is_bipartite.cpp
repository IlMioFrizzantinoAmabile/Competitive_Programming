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
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */

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