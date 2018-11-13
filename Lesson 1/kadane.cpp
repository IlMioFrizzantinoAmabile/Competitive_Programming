#include<bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin>>T;
	for (int i=0;i<T;i++) {
		int N;
		cin>>N;
		int curr=0;
		int max=-1000000;
		for (int j=0;j<N;j++) {
			int tmp;
			cin>>tmp;
			if (curr<0) curr=0;
			curr+=tmp;
			if (curr>max) max=curr;
		}
		cout<<max<<endl;
	}
	return 0;
}