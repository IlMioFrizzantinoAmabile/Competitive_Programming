/* Given an array C of size N-1 and given that there are numbers from 1 to N with one element missing, the missing number is to be found.
 * Input:
 * The first line of input contains an integer T denoting the number of test cases.
 * For each test case first line contains N, size of array. The second line contains N-1 array elements.
 * Output:
 * Print the missing number in array.
 * SOURCE: https://practice.geeksforgeeks.org/problems/missing-number-in-array/0
 */

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int T;
	cin>>T;
	for (int j=0;j<T;j++) {
		int N;
		cin>>N;
		ll sum=0;
		for (int i=1;i<N;i++) {
			int num;
			cin>>num;
			sum+=num;
		}
		ll miss = N*(N+1)/2 - sum;
		cout<<miss<<endl;
	}
	return 0;
}
