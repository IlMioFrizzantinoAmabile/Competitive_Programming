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