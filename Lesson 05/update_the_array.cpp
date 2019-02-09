/* PROBLEM
 * You have an array containing n elements initially all 0.
 * You need to do a number of update operations on it.
 * In each update you specify l, r and val which are the starting index, ending index and value to be added.
 * After each update, you add the 'val' to all elements from index l to r.
 * After 'u' updates are over, there will be q queries each containing an index for which you have to print the element at that index.
 * Input:
 * First line consists of t, the number of test cases.
 * Each test case consists of "n u",number of elements in the array and the number of update operations, in the first line.
 * Then follow u lines each of the format "l r val".
 * Next line contains q, the number of queries.
 * Next q lines contain an index.
 * Output:
 * For each test case, output the answers to the corresponding queries in separate lines.
 * SOURCE: https://www.spoj.com/problems/UPDATEIT/
 *
 * SOLUTION
 * L'algoritmo memorizza gli updates come +val e -val rispettivamente negli estremi dell'intervallo, in tempo lineare.
 * Esegue una prefix sum di questo array, calcolando così tutte le updates contemporaneamente, in tempo lineare.
 * Restituisce il risultato semplicemente leggendo il valore, in tempo lineare.
 * COMPLEXITY: O(u+n+q)
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int T;
	cin>>T;
	for (int t=0;t<T;t++) {
		int n,u;
		cin>>n>>u;
		vector<int> vec(n+1,0);
		for (int i=0;i<u;i++) {
			int l,r,val;
			cin>>l>>r>>val;
			vec[l]+=val;
			vec[r+1]-=val;
		}
		for (int i=1;i<=n;i++) {
			vec[i]+=vec[i-1];
		}
		int Q;
		cin>>Q;
		for (int q=0;q<Q;q++) {
			int i;
			cin>>i;
			cout<<vec[i]<<endl;
		}
	}
	return 0;
}
