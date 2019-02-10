/* PROBLEM
 * Given a sequence, find the length of the longest increasing subsequence from a given sequence .
 * The longest increasing subsequence means to find a subsequence of a given sequence in which the subsequence's elements are
 * in sorted order, lowest to highest, and in which the subsequence is as long as possible.
 * This subsequence is not necessarily contiguous, or unique.
 * Note: Duplicate numbers are not counted as increasing subsequence.
 * Input:
 * The first line contains an integer T, depicting total number of test cases. 
 * Then following T lines contains an integer N depicting the size of array and next line followed by the value of array.
 * Output:
 * Print the Max length of the subsequence in a separate line.
 * SOURCE: https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
 *
 * SOLUTION
 * L'algoritmo utilizza la programmazione dinamica risolvendo i sottoproblemi dati dai prefissi.
 * Inoltre il passaggio da un prefisso al successivo ha costo logaritmico anzichè lineare (nella lunghezza del prefisso) grazie
 * ad una binary search.
 * COMPLEXITY: O(N*log(N))
 */

#include<bits/stdc++.h>

using namespace std;

int longestIncreasingSequence(int n, int* array) {
	int LIS[1001],dominant[1002],max=0;
	dominant[0]=0;
	for (int i=1;i<=n;i++) dominant[i]=1000000000;
	for (int i=0;i<n;i++) {
		int start=0,end=i+1;
		while (start!=end) { //binary search sui dominant
			int mid = (end+start+1)/2;  //metà= metà o metà+(1/2)
			if (dominant[mid] < array[i]) start=mid; 	//se la successione è fortemente crescente provo valori maggiori
			else end = mid-1;							//sennò provo valori minori
		}
		LIS[i] = 1 + start;
		if (array[i] < dominant[LIS[i]])	dominant[LIS[i]] = array[i];
		if (LIS[i]>max) max=LIS[i];
	}
	return max;
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
		int array[1001];
		for (int i=0;i<n;i++) cin>>array[i];
		cout<<longestIncreasingSequence(n,array)<<endl;
	}
	return 0;
}
