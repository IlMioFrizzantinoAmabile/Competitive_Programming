#include<bits/stdc++.h>

using namespace std;

int tab[101][101];

int LCS (string s, string t) {
	for (int i=1;i<=s.length();i++) for (int j=1;j<=t.length();j++) {
		if (i==0 or j==0) 			tab[i][j] = 0;
		else if (s[i-1]==t[j-1])	tab[i][j] = 1+tab[i-1][j-1];
		else 						tab[i][j] = max(tab[i][j-1],tab[i-1][j]);
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
		int n,m;
		cin>>n>>m;
		string s,t;
		cin>>s>>t;
		cout<<LCS(s,t)<<endl;
	}
	return 0;
}