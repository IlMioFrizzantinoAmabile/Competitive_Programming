#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> bars(n);
	int sum=0;
	for (int i=0;i<n;i++) {
		cin>>bars[i];
		sum+=bars[i];
	}
	int partialAlice=0;
	int alice=0;
	while (2*partialAlice<=sum) partialAlice+=bars[alice++];
	int partialBob = sum-partialAlice;
	partialAlice-= bars[--alice];
	if (partialAlice<=partialBob) alice++;
	cout<<alice<<" "<<n-alice;
	return 0;
}