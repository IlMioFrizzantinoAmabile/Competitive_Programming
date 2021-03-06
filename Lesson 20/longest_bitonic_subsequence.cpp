/* PROBLEM
 * Given an array of positive integers. The task is to print the maximum length of Bitonic subsequence. 
 * A subsequenceof array is called Bitonic if it is first increasing, then decreasing.
 * Input:
 * First line contains T test cases.
 * First line of every test case consists of N , denoting number of elements in an array.
 * Second line of every test consists of elements in array.
 * Output:
 * Single line output, print the longest bitonic sequence.
 * SOURCE: https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence/0
 *
 * SOLUTION
 * L'algoritmo utilizza la programmazione dinamica insieme ad un'astuta binary search per calcolare i longest increasing subsequence
 * per ogni prefisso. Inverte l'array e con la stessa strategia calcola i longest decreasing subsequence per i suffissi.
 * Fatto ciò scorre un'ultima volta l'array e trova la soluzione in tempo lineare.
 * COMPLEXITY: O(N*log(N))
 */

#include<bits/stdc++.h>

using namespace std;

#define MAXLENGTH 102

void longestIncreasingSequence(int n, int* array, int* LIS) {
	int dominant[MAXLENGTH],max=0;
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
	}
}
int longestBitonicSequence(int n, int* array) {
	int LincrS[MAXLENGTH], LdecrS[MAXLENGTH];
	longestIncreasingSequence(n,array,LincrS);
	reverse(array,array+n);
	longestIncreasingSequence(n,array,LdecrS);
	reverse(LdecrS,LdecrS+n);
	int max=0;
	for (int i=0;i<n;i++) {
		int pivot = LincrS[i]+LdecrS[i]-1;
		if (pivot>max) max=pivot;
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
		int array[MAXLENGTH];
		for (int i=0;i<n;i++) cin>>array[i];
		cout<<longestBitonicSequence(n,array)<<endl;
	}
	return 0;
}
