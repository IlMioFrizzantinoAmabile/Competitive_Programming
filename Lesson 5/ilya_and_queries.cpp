#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin>>s;
	int n = s.length();
	vector<int> sums(n);
	sums[0]=0;
	for (int i=1;i<n;i++) {
		if (s[i]==s[i-1]) sums[i]=sums[i-1]+1;
		else sums[i]=sums[i-1];
	}
	int m;
	cin>>m;
	for (int i=0;i<m;i++) {
		int l,r;
		cin>>l>>r;
		cout<<sums[r-1]-sums[l-1]<<endl;
	}
	return 0;
}