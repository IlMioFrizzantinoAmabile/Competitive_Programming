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