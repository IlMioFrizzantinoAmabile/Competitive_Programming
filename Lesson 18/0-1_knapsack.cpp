#include<bits/stdc++.h>

using namespace std;

int tab[101][101];

int knapsack(int N, int* value, int* weight, int W) {
	for (int n=0;n<=N;n++) for (int w=0;w<=W;w++) {
		if (n==0 or w==0) tab[n][w]=0;
		else {
			int up = tab[n-1][w];
			int left = (weight[n-1]>w) ? 0 : tab[n-1][w-weight[n-1]] + value[n-1];
			tab[n][w] = max(up, left);
		}
	}
	return tab[N][W];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while (T--){
		int n,W;
		cin>>n>>W;
		int value[101],weight[101];
		for (int i=0;i<n;i++) cin>>value[i];
		for (int i=0;i<n;i++) cin>>weight[i];
		cout<<knapsack(n,value,weight,W)<<endl;
	}
	return 0;
}