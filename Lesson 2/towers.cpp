#include<bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin>>N;
	vector<int> occ(1001,0);
	for(int i=0;i<N;i++) {
		int length;
		cin>>length;
		occ[length]++;
	}
	int max=0;
	int num=0;
	for(int i=1;i<=1000;i++)	if (occ[i]) {
		num++;
		if (occ[i]>max) max=occ[i];
	} 
	cout<<max<<" "<<num<<endl;
	return 0;
}