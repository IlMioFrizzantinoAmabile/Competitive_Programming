/* Given a String, find the longest palindromic subsequence.
 * Input:
 * The first line of input contains an integer T, denoting no of test cases.
 * The only line of each test case consists of a string S (only lowercase)
 * Output:
 * Print the Maximum length possible for palindromic subsequence.
 * SOURCE: https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence/0
 */

#include<bits/stdc++.h>

using namespace std;

int tab[1002][1002];

int longestPalindromicSequence(string s) {
	int len = s.length();
	int maxlen=0;
	for (int substrLeng=0;substrLeng<=len;substrLeng++) 
	    for (int i=0;i<=len-substrLeng;i++) {
    		int j=i+substrLeng;
    		if (substrLeng==0) 		tab[i][j] = 0;
    		else if (substrLeng==1) tab[i][j] = 1;
    		else if (s[i]==s[j-1])	tab[i][j] = 2 + tab[i+1][j-1];
    		else 					tab[i][j] = max(tab[i+1][j], tab[i][j-1]);
	    }
	return tab[0][len];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while (T--){
		string s;
		cin>>s;
		cout<<longestPalindromicSequence(s)<<endl;
	}
	return 0;
}
