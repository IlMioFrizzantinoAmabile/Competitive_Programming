/* Given an array A of size N having distinct elements,
 * the task is to find the next greater element for each element of the array in order of their appearance in the array.
 * If no such element exists, output -1
 * Input:
 * The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow.
 * Each test case consists of two lines.
 * The first line contains an integer N denoting the size of the array.
 * The Second line of each test case contains N space separated positive integers denoting the values/elements in the array A.
 * Output:
 * For each test case, print in a new line, the next greater element for each array element separated by space in order.
 * SOURCE: https://practice.geeksforgeeks.org/problems/next-larger-element/0
 */

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> gr;
stack<int> pila;

void aggiorna(ll x){
	gr[pila.top()] = x;
	pila.pop();
}

int main(){
	int T;
	cin>>T;
	for (int i=0;i<T;i++){
		int N;
		cin>>N;
		vector<ll> num(N);
		gr.reserve(N);
		for(int i=0; i<N; i++)	cin>>num[i];
		for(int i=0; i<N; i++) {
			while(!pila.empty() && num[pila.top()] < num[i]) aggiorna(num[i]);
			pila.push(i);
		}
		while(!pila.empty()) aggiorna(-1);
		for(int i=0; i<N; i++) cout<<gr[i]<<" ";
		cout<<endl;
	}
	return 0;
}
