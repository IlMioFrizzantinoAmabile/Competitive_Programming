/* You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the 
 * knapsack. Note that we have only one quantity of each item, In other words, given two integer arrays val[0..N-1] and wt[0..N-1]
 * which represent values and weights associated with N items respectively.
 * Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights
 * of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
 * Input:
 * The first line of input contains an integer T denoting the number of test cases.
 * Then T test cases follow. Each test case consists of four lines. 
 * The first line consists of N the number of items.
 * The second line consists of W, the maximum capacity of the knapsack.
 * In the next  line are N space separated positive integers denoting the values of the N items and 
 * in the fourth line are N space separated positive integers denoting the weights of the corresponding items.
 * Output:
 * Print the maximum possible value you can get with the given conditions that you can obtain for each test case in a new line.
 * SOURCE: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
 */

#include<bits/stdc++.h>

using namespace std;

int tab[101][101];

int knapsack(int N, int* value, int* weight, int W) {
	for (int n=0;n<=N;n++) for (int w=0;w<=W;w++) {
		if (n==0 or w==0) tab[n][w]=0;
		else {
			int up = tab[n-1][w];
			int left = (weight[n-1]>w) ? 0 : tab[n-1][w-weight[n-1]] + value[n-1];
			tab[n][w] = max(up, left);
		}
	}
	return tab[N][W];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while (T--){
		int n,W;
		cin>>n>>W;
		int value[101],weight[101];
		for (int i=0;i<n;i++) cin>>value[i];
		for (int i=0;i<n;i++) cin>>weight[i];
		cout<<knapsack(n,value,weight,W)<<endl;
	}
	return 0;
}
