#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

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