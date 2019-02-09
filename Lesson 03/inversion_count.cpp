/* PROBLEM
 * Let A[0...n - 1] be an array of n distinct positive integers.
 * If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A.
 * Given n and an array A your task is to find the number of inversions of A.
 * Input:
 * The first line contains t, the number of testcases followed by a blank space.
 * Each of the t tests start with a number n (n <= 200000). Then n + 1 lines follow.
 * In the ith line a number A[i - 1] is given (A[i - 1] <= 10^7). The (n + 1)th line is a blank space.
 * Output:
 * For every test output one line giving the number of inversions of A.
 * SOURCE: https://www.spoj.com/problems/INVCNT/
 *
 * SOLUTION
 * L'algoritmo funziona esattamente come un MergeSort ma in più ad ogni passaggio conta il numero di scambi, la complessità non aumenta.
 * COMPLEXITY: O(n*log(n))
 */

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> array,lleft,rright;

ll merge (int start, int end) {
	if (end-start > 1) {
		int length1 = (end-start)/2;
		int length2 = end - start - length1;
		ll pt1 = merge (start, start + length1);
		ll pt2 = merge (start + length1, end);
		for (int i = 0; i < length1; i++)	lleft[i] = array[start+i];
		for (int j = 0; j < length2; j++)	rright[j] = array[start+length1+j];
		int k=start, i=0, j=0, moltiplicatore=0;
		ll scambi=0;
		while (i < length1 && j < length2) {
			if (lleft[i] <= rright[j]) {
				array[k] = lleft[i];
				i++;
				scambi+=moltiplicatore;
			}
			else {
				array[k] = rright[j];
				j++;
				moltiplicatore++;
			}
			k++;
		}
		while (i < length1) {
			array[k] = lleft[i];
			i++;
			k++;
			scambi+=moltiplicatore;
		}
		while (j < length2) {
			array[k] = rright[j];
			j++;
			k++;
		}
		return scambi+pt1+pt2;
	}
	else return 0;
}

int main(){
	int T;
	cin>>T;
	for (int i=0;i<T;i++){
		int N;
		cin>>N;
		array.reserve(N);
		lleft.reserve(N);
		rright.reserve(N);
		for (int j=0;j<N;j++) {
			cin>>array[j];
		}
		cout<<merge(0,N)<<endl;
	}
	return 0;
}
