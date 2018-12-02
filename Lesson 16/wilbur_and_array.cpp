#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int abs(int x) {
	return x>0 ? x : -x;
}

int main(){
	int n;
	cin>>n;
	ll tot=0;
	int last=0,now;
	while(n--) {
		cin>>now;
		tot+=abs(last-now);
		last=now;
	}
	cout<<tot<<endl;
	return 0;
}