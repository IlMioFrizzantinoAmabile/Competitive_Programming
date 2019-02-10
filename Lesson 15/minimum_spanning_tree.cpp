/* PROBLEM
 * The task is to find the minimum spanning tree of the graph.
 * Input:
 * On the first line there will be two integers N, the number of nodes and M, the number of edges. (1 <= N <= 10000), (1 <= M <= 100000)
 * M lines follow with three integers i j k on each line representing an edge between node i and j with weight k.
 * The IDs of the nodes are between 1 and n inclusive. The weight of each edge will be <= 1000000.
 * Output:
 * Single number representing the total weight of the minimum spanning tree on this graph. There will be only one possible MST.
 * SOURCE: https://www.spoj.com/problems/MST/
 *
 * SOLUTION
 * Il programma implementa il ben noto algoritmo di Kruskal.
 * COMPLEXITY: O(M*log(M))
 */

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAX 10001

struct union_find {
	vector<int> parent;
	int numSubset;
	union_find(int n) : parent(n), numSubset(n) {
		for(int i=0;i<n;i++) parent[i]=i;
	}
	int Find(int target) {
		if (parent[target]!=target) parent[target]=Find(parent[target]);
		return parent[target];
	}
	void Union(int a, int b) {
		int rapprA = Find(a);
		int rapprB = Find(b);
		if (rapprA!=rapprB) {
			parent[rapprA]=rapprB;
			numSubset--;
		}
	}
};

struct edge {
	int a,b;
	int weight;
	int index;
};
struct comp{
	bool operator()(const edge& a, const edge& b){
		return a.weight < b.weight;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<edge> graph(m);
	for (int i=0;i<m;i++) {
		int a,b,w;
		cin>>a>>b>>w;
		graph[i].a=a;
		graph[i].b=b;
		graph[i].weight=w;
		graph[i].index=i;
	}
	sort(graph.begin(),graph.end(),comp());
	union_find UF(MAX);
	ll totWeight=0;
	for (vector<edge>::iterator it=graph.begin(); it!=graph.end(); it++) {
		int a=it->a;
		int b=it->b;
		if (UF.Find(a)!=UF.Find(b)) {
			UF.Union(a,b);
			totWeight+=it->weight;
			if (UF.numSubset==1) break;
		}
	}
	cout<<totWeight<<endl;
	return 0;
}
