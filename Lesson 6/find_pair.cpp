#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct compare{
	bool operator()(const int& a, const int& b){
		return a < b;
	}
};

int main(){
	ll n,k;
	cin>>n>>k;
	vector<int> vet(n);
	for (int i=0;i<n;i++) cin>>vet[i];
	sort(vet.begin(),vet.end(),compare());
	vector<int> same(n,1);
	bool rep=false;
	for (int i=1;i<n;i++) if (vet[i]==vet[i-1]) {
		rep=true;
		same[i]+=same[i-1];
	}
	int first = (k-1)/n;
	int i=first;
	int position = same[i];
	if (i<n-1) while (same[i]+1==same[++i]) {}
	else i++;
	int repetition = same[--i];
	int second = (k-1)%n;
	second = ((position-1)*n+second)/repetition;
	cout<<vet[first]<<" "<<vet[second]<<endl;
	return 0;
}