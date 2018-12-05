/* Given an array of integers where each element represents the max number of steps that can be made forward from that element.
 * Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). 
 * If an element is 0, then cannot move through that element.
 * Input: 
 * The first line contains an integer T, depicting total number of test cases. 
 * Then following T lines contains a number n denoting the size of the array.
 * Next line contains the sequence of integers a1, a2, ..., an.
 * Output:
 * Each seperate line showing the minimum number of jumps. If answer is not possible print -1.
 * SOURCE: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
 */

#include<bits/stdc++.h>

using namespace std;

int minJumps(int n, int* array) {
	int maxReach=array[0],step=array[0],jump=1;
	if (!maxReach) return -1;
	for (int i=1;i<n-1;i++) {
		step--;
		maxReach = max(maxReach,i+array[i]);
		if (!step) {
			if (maxReach<=i) return -1;
			jump++;
			step = maxReach-i;
		}
	}
	return jump;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while (T--){
		int n;
		cin>>n;
		int array[101];
		for (int i=0;i<n;i++) cin>>array[i];
		cout<<minJumps(n,array)<<endl;
	}
	return 0;
}
