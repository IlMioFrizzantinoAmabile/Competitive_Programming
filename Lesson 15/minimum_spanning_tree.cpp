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