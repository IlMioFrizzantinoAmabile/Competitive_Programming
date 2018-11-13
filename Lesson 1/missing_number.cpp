#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int T;
	cin>>T;
	for (int j=0;j<T;j++) {
		int N;
		cin>>N;
		ll sum=0;
		for (int i=1;i<N;i++) {
			int num;
			cin>>num;
			sum+=num;
		}
		ll miss = N*(N+1)/2 - sum;
		cout<<miss<<endl;
	}
	return 0;
}