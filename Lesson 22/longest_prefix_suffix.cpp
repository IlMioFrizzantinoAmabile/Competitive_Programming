#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while (T--){
		string s;
		cin>>s;
		vector<int> ans(s.length());
		ans[0]=0;
		int prefixEnd=0;
		for (int suffixEnd=1; suffixEnd<s.length(); suffixEnd++) {
			while (s[prefixEnd]!=s[suffixEnd] && prefixEnd!=0)	prefixEnd=ans[prefixEnd-1];
			if (s[prefixEnd]==s[suffixEnd])	prefixEnd++;
			ans[suffixEnd]=prefixEnd;
		}
		cout<<ans[s.length()-1]<<endl;
	}
	return 0;
}