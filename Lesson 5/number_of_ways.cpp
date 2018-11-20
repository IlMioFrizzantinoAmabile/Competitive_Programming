#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin>>n;
	vector<int> vet(n);
	ll sum=0,tot=0;
	for (int i=0;i<n;i++) {
		cin>>vet[i];
		sum+=vet[i];
	}
	if (sum%3!=0) cout<<0<<endl;
	else {
		sum/=3;
		ll provv=0;
		vector<int> left(n,0);
		for (int i=0;i<n;i++) {
			provv+=vet[i];
			if (provv==sum) left[i]=1;
		}
		for (int i=1;i<n;i++) {
			left[i]+=left[i-1];
		}
		provv=0;
		for (int i=n-1;i>1;i--) {
			provv+=vet[i];
			if (provv==sum) tot+=left[i-2];
		}
		cout<<tot<<endl;
	}
	return 0;
}