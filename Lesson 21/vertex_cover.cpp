/* You are given an unweighted, undirected tree.
 * The task is to find a vertex set of minimum size in this tree such that each edge has as least one of its end-points in that set.
 * Input:
 * The first line of the input file contains one integer N, number of nodes in the tree. 
 * Next N-1 lines contain N-1 edges of that tree.
 * Each line contains a pair (u, v) means there is an edge between node u and node v (1 <= u,v <= N).
 * Output:
 * Print number of nodes in the satisfied vertex set on one line.
 * SOURCE: https://www.spoj.com/problems/PT07X/
 */

#include<bits/stdc++.h>

using namespace std;

#define MAXN 100001
#define BIG 1000000000

set<int> sons[MAXN];

pair<int,int> dfsVC (int node, int dad) {
	int minSI=1, minNO=0;
	set<int>::iterator it;
	for (it=sons[node].begin(); it!=sons[node].end(); it++) {
		int son=*it;
		if (son!=dad) {
			pair<int,int> res;
			res = dfsVC(son,node);
			minNO += res.first;
			minSI += min(res.first,res.second);
		}
	}
	return make_pair(minSI,minNO);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<n;i++) {
		int a,b;
		cin>>a>>b;
		sons[--a].insert(--b);
		sons[b].insert(a);
	}
	pair<int,int> result = dfsVC(0,-1);
	cout<<min(result.first, result.second)<<endl;
	return 0;
}
