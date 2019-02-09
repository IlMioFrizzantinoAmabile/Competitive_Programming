/* PROBLEM
 * Ilya the Lion wants to help all his friends with passing exams. They need to solve the following problem to pass the IT exam.
 * You've got string s = s1s2... sn (n is the length of the string), consisting only of characters "." and "#" and m queries.
 * Each query is described by a pair of integers li, ri (1 ≤ li < ri ≤ n).
 * The answer to the query li, ri is the number of such integers i (li ≤ i < ri), that si = si + 1.
 * Ilya the Lion wants to help his friends but is there anyone to help him? Help Ilya, solve the problem.
 * Input:
 * The first line contains string s of length n.
 * It is guaranteed that the given string only consists of characters "." and "#".
 * The next line contains integer m, the number of queries.
 * Each of the next m lines contains the description of the corresponding query. The i-th line contains integers li, ri (1 ≤ li < ri ≤ n).
 * Output:
 * Print m integers — the answers to the queries in the order in which they are given in the input.
 * SOURCE: http://codeforces.com/problemset/problem/313/B?locale=en
 *
 * SOLUTION
 * L'algoritmo calcola il prefix sum dell'array booleano A[i] = (si==si-1), con true=1 e false=0.
 * La risposta ad ogni query è quindi trovata per differenza negli estremi
 * COMPLEXITY: O(n+m)
 */

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
