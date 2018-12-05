#include<bits/stdc++.h>

using namespace std;

int minJumps(int n, int* array) {
	int maxReach=array[0],step=array[0],jump=1;
	if (!maxReach) return -1;
	for (int i=1;i<n-1;i++) {
		step--;
		maxReach = max(maxReach,i+array[i]);
		if (!step) {
			if (maxReach<=i) return -1;
			jump++;
			step = maxReach-i;
		}
	}
	return jump;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while (T--){
		int n;
		cin>>n;
		int array[101];
		for (int i=0;i<n;i++) cin>>array[i];
		cout<<minJumps(n,array)<<endl;
	}
	return 0;
}