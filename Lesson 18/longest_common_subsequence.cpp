/* /* Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.
 * Input:
 * First line of the input contains no of test cases T, the T test cases follow.
 * Each test case consist of 2 space separated integers A and B denoting the size of string str1 and str2 respectively
 * The next two lines contains the 2 string str1 and str2 .
 * Output:
 * For each test case print the length of longest common subsequence of the two strings .
 * SOURCE: https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
 */

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
