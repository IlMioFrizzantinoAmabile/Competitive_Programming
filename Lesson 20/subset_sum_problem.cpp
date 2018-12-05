#include<bits/stdc++.h>

using namespace std;

bool tab[102][100300];

bool subsetSum(int* set, int n, int sum) {
	for (int i=0;i<=n;i++) for (int j=0;j<=sum;j++) {
		if (i==0)			tab[i][j]=false;
		else if (j==0)		tab[i][j]=true;
		else {
			int leftJ = j-set[i-1];
			if (leftJ<0)	tab[i][j] = tab[i-1][j];
			else 			tab[i][j] = tab[i-1][j] or tab[i-1][leftJ];
		}
	}
	return tab[n][sum];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while (T--){
		int n;
		cin>>n;
		int set[101];
		int totSum=0;
		for (int i=0;i<n;i++) {
			cin>>set[i];
			totSum+=set[i];
		}
		int meta=totSum/2;
		if (meta+meta!=totSum) cout<<"NO"<<endl;
		else if (subsetSum(set,n,meta)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}