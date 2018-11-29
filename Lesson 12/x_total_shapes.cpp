#include<bits/stdc++.h>

using namespace std;

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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while (T--) {
		int N,M;
		cin>>N>>M;
		bool X[N][M];
		int bind[N][M];
		int numX=0;
		for (int i=0;i<N;i++) for (int j=0;j<M;j++) {
			char c;
			cin>>c;
			if (c=='X') {
				X[i][j]=true;
				bind[i][j]=numX;
				numX++;
			}
			else {
				X[i][j] = false;
			}
		}
		union_find shapes(numX);
		for (int i=0;i<N;i++) for (int j=0;j<M;j++) if (X[i][j]) {
			if (i and X[i-1][j])	shapes.Union(bind[i][j],bind[i-1][j]);
			if (j and X[i][j-1])	shapes.Union(bind[i][j],bind[i][j-1]);
		}
		cout<<shapes.numSubset<<endl;
	}
	return 0;
}