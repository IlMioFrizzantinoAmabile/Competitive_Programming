/* PROBLEM
 * Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.
 * Input:
 * The first line of input contains an integer T denoting the number of test cases.
 * The first line of each test case contains a single integer N denoting the size of array and the size of subarray K.
 * The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
 * Output:
 * Print the maximum for every subarray of size k.
 * SOURCE: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0
 *
 * SOLUTION
 * L'algoritmo utilizza una deque di coppie.
 * Il primo elemento di ogni coppia è il valore di un elemento dell'array, il secondo è la sua posizione.
 * L'algoritmo scorre l'array. In ogni momento i primi valori delle coppie nella deque sono in ordine decrescente (*).
 * Ad ogni passo legge un nuovo valore (x) dell'array.
 * Elimina dalla deque tutti gli elementi che non sono più nel range di interesse (i-k,i] e tutti gli elementi più piccoli di x.
 * Aggiunge l'elemento x in fondo dalla deque. Questo garantisce il mantenimento della proprietà (*).
 * Il massimo nel range è quindi dato dall'elemento in testa alla deque.
 * COMPLEXITY: O(n)
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
