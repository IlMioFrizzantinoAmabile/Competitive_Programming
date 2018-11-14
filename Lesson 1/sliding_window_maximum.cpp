/* Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.
 * Input:
 * The first line of input contains an integer T denoting the number of test cases.
 * The first line of each test case contains a single integer N denoting the size of array and the size of subarray K.
 * The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
 * Output:
 * Print the maximum for every subarray of size k.
 * SOURCE: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0
 */

#include<bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin>>T;
	for (int j=0;j<T;j++) {
		int N,k;
		cin>>N>>k;
		deque<pair<int,int>> deq;
		for(int i=0; i<N; i++){
			if(!deq.empty() && i-deq.front().second>=k) deq.pop_front();
			int x;
			cin>>x;
			while(!deq.empty() && deq.back().first<x) deq.pop_back();
			deq.push_back(make_pair(x,i));
			if(i>=k-1) cout<<deq.front().first<<" ";
		}
		cout<<endl;
	}
	return 0;
}
