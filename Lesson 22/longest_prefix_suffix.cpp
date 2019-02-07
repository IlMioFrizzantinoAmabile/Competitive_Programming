/* Given a string of character, find the length of longest proper prefix which is also a proper suffix.
 * Input:
 * First line is T number of test cases. 1<=T<=100.
 * Each test case has one line denoting the string of length less than 100000.
 * Output:
 * Print length of longest proper prefix which is also a proper suffix.
 * SOURCE: https://practice.geeksforgeeks.org/problems/longest-prefix-suffix/0
 */

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
