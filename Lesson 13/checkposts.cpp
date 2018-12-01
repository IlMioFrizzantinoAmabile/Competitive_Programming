#include<bits/stdc++.h>

using namespace std;

const int MODULO = 1000000007;

vector< vector<int> > edge;
vector< vector<int> > edgeREV;
vector<int> color;
int TIME;
vector< pair<int,int> > finish;
vector<int> belongSCC;

void DFS(int node) {
	color[node]=1; //grigio
	vector<int>::iterator it;
	for (it=edge[node].begin(); it!=edge[node].end(); it++)
		if (color[*it]==0) 
			DFS(*it);
	finish[node]=make_pair(TIME++,node);
}
void reverseDFS(int node, int SCC) {
	color[node]=1; //grigio
	vector<int>::iterator it;
	for (it=edgeREV[node].begin(); it!=edgeREV[node].end(); it++)
		if (color[*it]==0) 
			reverseDFS(*it, SCC);
	belongSCC[node]=SCC;
}

int CountSCC (int dim) {
	color.assign(dim,0);
	finish.assign(dim,make_pair(0,0));
	TIME=0;
	for (int i=0;i<dim;i++) if(color[i]==0) DFS(i);
	
	sort(finish.begin(),finish.end());
	reverse(finish.begin(),finish.end());
	
	color.assign(dim,0);
	belongSCC.reserve(dim);
	int SCC=0;
	vector< pair<int,int> >::iterator it;
	for (it=finish.begin(); it!=finish.end(); it++) 
		if(color[it->second]==0)
			reverseDFS(it->second, SCC++);
	return SCC;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<int> cost(n);
	for (int i=0;i<n;i++) cin>>cost[i];
	
	edge.reserve(n);
	edgeREV.reserve(n);
	int m;
	cin>>m;
	while (m--) {
		int u,v;
		cin>>u>>v;
		u--;v--;
		edge[u].push_back(v);
		edgeREV[v].push_back(u);
	}
	int SCC = CountSCC(n);
	
	vector<int> minCost(SCC,100000000);
	for (int node=0;node<n;node++)
		if (cost[node] < minCost[belongSCC[node]]) 
			minCost[belongSCC[node]] = cost[node];
	vector<int> poxChoice(SCC,0);
	for (int node=0;node<n;node++) 
		if (cost[node] == minCost[belongSCC[node]]) 
			poxChoice[belongSCC[node]]++;
	int totCost=0,totPox=1;
	for (int i=0;i<SCC;i++)	{
		totCost+=minCost[i];
		totPox=(totPox*poxChoice[i])%MODULO;
	}	
	cout<<totCost<<" "<<totPox<<endl;
	return 0;
}