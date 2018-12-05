#include<bits/stdc++.h>

using namespace std;

int tab[102][102];

int editDistance(string s, string t) {
	for (int i=0;i<=s.length();i++) for (int j=0;j<=t.length();j++) {
		if (i==0 or j==0) tab[i][j] = max(i,j);
		else if (s[i-1]==t[j-1])	tab[i][j] = tab[i-1][j-1];
		else {
			int up = tab[i-1][j];
			int left = tab[i][j-1];
			int diag = tab[i-1][j-1];
			tab[i][j] = 1 + min(min(up,left),diag);
		}
	}
	return tab[s.length()][t.length()];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while (T--){
		int p,q;
		cin>>p>>q;
		string s,t;
		cin>>s>>t;
		cout<<editDistance(s,t)<<endl;
	}
	return 0;
}