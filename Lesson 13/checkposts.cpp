/* Your city has n junctions. There are m one-way roads between the junctions. As a mayor of the city, you have to ensure the 
 * security of all the junctions. To ensure the security, you have to build some police checkposts. Checkposts can only be built 
 * in a junction. A checkpost at junction i can protect junction j if either i = j or the police patrol car can go to j from i 
 * and then come back to i.
 * Building checkposts costs some money. As some areas of the city are more expensive than others, building checkpost at some
 * junctions might cost more money than other junctions.
 * You have to determine the minimum possible money needed to ensure the security of all the junctions.
 * Also you have to find the number of ways to ensure the security in minimum price and in addition in minimum number of checkposts.
 * Two ways are different if any of the junctions contains a checkpost in one of them and do not contain in the other.
 * Input:
 * In the first line, you will be given an integer n, number of junctions. In the next line, n space-separated integers will be given.
 * The ith integer is the cost of building checkpost at the ith junction (costs will be non-negative and will not exceed 10^9).
 * The next line will contain an integer m. And each of the next m lines contains two integers ui and vi (1 ≤ ui, vi ≤ n; u ≠ v).
 * A pair ui, vi means, that there is a one-way road which goes from ui to vi. There will not be more than one road between 
 * two nodes in the same direction.
 * Output:
 * Print two integers separated by spaces.
 * The first one is the minimum possible money needed to ensure the security of all the junctions.
 * And the second one is the number of ways you can ensure the security modulo 1000000007.
 * SOURCE: http://codeforces.com/problemset/problem/427/C?locale=en
 */

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
