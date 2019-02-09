/* Given an array, write a program that prints 1 if given array can represent preorder traversal of a BST, else prints 0.
 * Input:
 * The first line of input contains an integer T denoting the number of test cases.
 * The first line of each test case is N, the size of array.
 * The second line of each test case contains N input A[i].
 * Output:
 * Should print 1 if given array can represent preorder traversal of BST. Otherwise 0.
 * SOURCE: https://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst/0
 *
 * SOLUTION
 * L'algoritmo fissa il primo elemento dell'array come radice e verifica che sia possibile dividere il resto dell'array in due
 * intervalli in modo che gli elementi del primo (left_branch=1) siano minori di radice, e gli elementi del secondo (left_branch=0) siano maggiori.
 * Fatto questo richiama se stessa ricorsivamente sui due intervalli trovati.
 * COMPLEXITY: O(n*log(n))
 */

#include<bits/stdc++.h>

using namespace std;

vector<int> vec;

int check_BST(int root, int end) {
	if (end-root<2) return 1;
	int left_branch = 1;
	int last=end;
	for (int i=root+1; i<=end; i++) {
		if (vec[i]>vec[root]) {
			if (left_branch) {
				left_branch=0;
				last=i;
			}
		}
		else if (!left_branch) return 0;
	}
	return check_BST(root+1,last) * check_BST(last+1,end);
}

int main(){
	int T;
	cin>>T;
	for (int i=0;i<T;i++){
		int N;
		cin>>N;
		vec.reserve(N);
		for (int i=0;i<N;i++) cin>>vec[i];
		cout<<check_BST(0,N-1)<<endl;
	}
	return 0;
}
