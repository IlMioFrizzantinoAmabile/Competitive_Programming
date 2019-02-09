/* PROBLEM
 * Given an array containing both negative and positive integers. Find the contiguous sub-array with maximum sum.
 * Input:
 * The first line of input contains an integer T denoting the number of test cases.
 * The first line of each test case contains a single integer N denoting the size of array.
 * The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
 * Output:
 * Print the maximum sum of the contiguous sub-array in a separate line for each test case.
 * SOURCE: https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
 *
 * SOLUTION
 * L'algoritmo scorre l'array tenendo in memoria il massimo (max) raggiunto fino a quel punto e il massimo (curr) raggiunto
 * dall'ultimo suffisso di numeri positivi.
 * COMPLEXITY: O(n)
 */

#include<bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin>>T;
	for (int i=0;i<T;i++) {
		int N;
		cin>>N;
		int curr=0;
		int max=-1000000;
		for (int j=0;j<N;j++) {
			int tmp;
			cin>>tmp;
			if (curr<0) curr=0;
			curr+=tmp;
			if (curr>max) max=curr;
		}
		cout<<max<<endl;
	}
	return 0;
}
