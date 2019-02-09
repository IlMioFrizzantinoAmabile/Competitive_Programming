/* PROBLEM
 * Little Vasya has received a young builder’s kit.
 * The kit consists of several wooden bars, the lengths of all of them are known.
 * The bars can be put one on the top of the other if their lengths are the same.
 * Vasya wants to construct the minimal number of towers from the bars. Help Vasya to use the bars in the best way possible.
 * Input:
 * The first line contains an integer N (1 ≤ N ≤ 1000), the number of bars at Vasya’s disposal.
 * The second line contains N space-separated integers li, the lengths of the bars. All the lengths are natural numbers not exceeding 1000.
 * Output:
 * In one line output two numbers, the height of the largest tower and their total number. Remember that Vasya should use all the bars.
 * SOURCE: http://codeforces.com/problemset/problem/37/A?locale=en
 *
 * SOLUTION
 * L'algoritmo scorre l'array delle lunghezze e memorizza solo le occorrenze di ciascuna lunghezza.
 * Scorre l'array delle occorrenze e conta quante sono diverse da 0, numero di torri, e memorizza qual è il valore massimo, l'altezza.
 * COMPLEXITY: O(n)
 */

#include<bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin>>N;
	vector<int> occ(1001,0);
	for(int i=0;i<N;i++) {
		int length;
		cin>>length;
		occ[length]++;
	}
	int max=0;
	int num=0;
	for(int i=1;i<=1000;i++)	if (occ[i]) {
		num++;
		if (occ[i]>max) max=occ[i];
	} 
	cout<<max<<" "<<num<<endl;
	return 0;
}
