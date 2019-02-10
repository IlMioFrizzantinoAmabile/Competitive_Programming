/* PROBLEM
 * Given two strings str1 and str2 and below operations that can performed on str1.
 * Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.
 * -Insert
 * -Remove
 * -Replace
 * All of the above operations are of cost=1.
 * Both the strings are of lowercase.
 * Input:
 * The First line of the input contains an integer T denoting the number of test cases.
 * Then T test cases follow. Each tese case consists of two lines. 
 * The first line of each test case consists of two space separated integers P and Q denoting the length of the strings str1 and str2 respectively.
 * The second line of each test case coantains two space separated strings str1 and str2 in order.
 * Output:
 * Corresponding to each test case, pirnt in a new line, the minimum number of operations required.
 * SOURCE: https://practice.geeksforgeeks.org/problems/edit-distance/0
 *
 * SOLUTION
 * L'algoritmo utilizza la programmazione dinamica risolvendo i sottoproblemi dati dai prefissi delle stringhe
 * COMPLEXITY: O(P*Q)
 */

#include<bits/stdc++.h>

using namespace std;

int tab[102][102];

int editDistance(string s, string t) {
	for (int i=0;i<=s.length();i++) for (int j=0;j<=t.length();j++) {
		if (i==0 or j==0) 		tab[i][j] = max(i,j);
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
