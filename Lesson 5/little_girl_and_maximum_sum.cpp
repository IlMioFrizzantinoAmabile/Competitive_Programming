#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct compare{
	bool operator()(const int& a, const int& b){
		return a > b;
	}
};

int main(){
	int n,q;
	cin>>n>>q;
	vector<int> vet(n);
	for (int i=0;i<n;i++) cin>>vet[i];
	vector<ll> quer(n+1,0);
	for (int i=0;i<q;i++) {
		int l,r;
		cin>>l>>r;
		quer[l-1]++;
		quer[r]--;
	}
	for (int i=1;i<=n;i++) quer[i]+=quer[i-1];
	sort(vet.begin(),vet.end(),compare());
	sort(quer.begin(),--quer.end(),compare());
	ll max=0;
	for (int i=0;i<n;i++) max+=vet[i]*quer[i];
	cout<<max<<endl;
	return 0;
}