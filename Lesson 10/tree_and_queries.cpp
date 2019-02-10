/* PROBLEM
 * You have a rooted tree consisting of n vertices. Each vertex of the tree has some color.
 * We will assume that the tree vertices are numbered by integers from 1 to n. Then we represent the color of vertex v as cv.
 * The tree root is a vertex with number 1.
 * In this problem you need to answer to m queries. Each query is described by two integers vj, kj.
 * The answer to query vj, kj is the number of such colors of vertices x, that the subtree of vertex vj contains
 * at least kj vertices of color x.
 * Input:
 * The first line contains two integers n and m.
 * The next line contains a sequence of integers c1, c2, ..., cn. 
 * The next n - 1 lines contain the edges of the tree.
 * The i-th line contains the numbers ai, bi (1 ≤ ai, bi ≤ n; ai ≠ bi), the vertices connected by an edge of the tree.
 * Next m lines contain the queries. The j-th line contains two integers vj, kj.
 * Output:
 * Print m integers — the answers to the queries in the order the queries appear in the input.
 * SOURCE: http://codeforces.com/contest/375/problem/D
 *
 * SOLUTION
 * L'algoritmo tramite una DFS riporta l'albero in un array, mantenendo le proprietà dei sottoalberi.
 * Dopodichè grazie all'algoritmo di MOs sorta le query in modo ottimale.
 * COMPLEXITY: O(sqrt(n)*(n+m))
 */

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

double sqrtN;
int occ[100001];
int occAtLeast[100001];

struct range {
	int left,right,k;
	int index;
	int answer;
};

struct compMOs{
	bool operator()(const range& a, const range& b){
		int blockA = (int) a.left/sqrtN;
		int blockB = (int) b.left/sqrtN;
		if (blockA<blockB) return true;
		else if (blockA>blockB) return false;
		else return a.right < b.right;
	}
};
struct comp{
	bool operator()(const range& a, const range& b){
		return a.index < b.index;
	}
};

void add(int i, vector<int>& col) {
	occ[col[i]]++;
	occAtLeast[occ[col[i]]]++;
	
}
void remove(int i, vector<int>& col) {
	occAtLeast[occ[col[i]]]--;
	occ[col[i]]--;
}

int tmp=1;
void DFS(int node, int father, vector<int>& OldCol, vector<int>& NewCol, vector< vector<int> >& sons, vector< pair<int,int> >& subtree) {
	NewCol[tmp]=OldCol[node];
	subtree[node].first=tmp;
	tmp++;
	for (vector<int>::iterator it=sons[node].begin(); it!=sons[node].end(); it++) {
		if (*it!=father)	DFS(*it,node,OldCol,NewCol,sons,subtree);
	}
	subtree[node].second=tmp-1;
}
	
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	sqrtN=sqrt(n);
	vector<int> OldCol(n+1), NewCol(n+1);
	vector<range> query(m);
	for (int i=1;i<=n;i++) cin>>OldCol[i];
	vector< vector<int> > sons(n+1);
	for (int i=1;i<n;i++) {
		int a,b;
		cin>>a>>b;
		sons[a].push_back(b);
		sons[b].push_back(a);
	}
	vector< pair<int,int> > subtree(n+1);
	DFS(1,-1,OldCol,NewCol,sons,subtree);
	for (int i=0;i<m;i++) {
		int node;
		cin>>node>>query[i].k;
		query[i].index = i;
		query[i].left = subtree[node].first;
		query[i].right = subtree[node].second;
	}
	sort(query.begin(),query.end(),compMOs());
	int currLeft=0,currRight=0;
	for (vector<range>::iterator currQuery = query.begin(); currQuery!=query.end(); currQuery++) {
		while (currLeft < currQuery->left) {
			remove(currLeft,NewCol);
			currLeft++;
		}
		while (currLeft > currQuery->left) {
			currLeft--;
			add(currLeft,NewCol);
		}
		while (currRight < currQuery->right) {
			currRight++;
			add(currRight,NewCol);
		}
		while (currRight > currQuery->right) {
			remove(currRight,NewCol);
			currRight--;
		}
		currQuery->answer = occAtLeast[currQuery->k];
	}
	sort(query.begin(),query.end(),comp());
	for (int i=0;i<m;i++) cout<<query[i].answer<<endl;
	return 0;
}
