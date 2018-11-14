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