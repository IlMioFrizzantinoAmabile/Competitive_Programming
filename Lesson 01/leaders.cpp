/* PROBLEM
 * Given an array of positive integers. The task is to find the leaders in the array.
 * An element of array is leader if it is greater than or equal to all the elements to its right side.
 * Input:
 * The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
 * The first line of each test case contains a single integer N denoting the size of array.
 * The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
 * Output:
 * Print all the leaders.
 * SOURCE: https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0
 *
 * SOLUTION
 * L'algoritmo scorre l'array partendo da destra, tenendo in memoria il massimo (max) raggiunto fino a quel punto.
 * COMPLEXITY: O(n)
 */

#include<bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin>>T;
	for (int i=0;i<T;i++){
		int N;
		cin>>N;
		vector<int> num(N);
		for (int j=0;j<N;j++) cin>>num[j];
		int max=num[N-1];
		list<int> leaders;
		for(int j=N-1;j>=0;j--){
			if (num[j]>=max)	{
				leaders.push_front(num[j]);
				max=num[j];
			}
		}
		for(list<int>::iterator it = leaders.begin(); it!=leaders.end(); it++) cout<<*it<<" ";
		cout<<endl;
	}
	return 0;
}
