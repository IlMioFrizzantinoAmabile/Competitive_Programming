#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> val(2*n);
	vector<int> occ(100,0);
	vector<int> heap1(100,0);
	for (int i=0;i<2*n;i++) {
		cin>>val[i];
		occ[val[i]]++;
	}
	int card1=0, card2=0, tot1=0, tot2=0;
	
	for (int i=10;i<100;i++) if (occ[i]>=2) {
			card1++;
			card2++;
			int meta = occ[i]/2;
			int bigmeta = occ[i]-meta;
			if (tot1 < tot2) {
				heap1[i]+=bigmeta;
				tot1+=bigmeta;
				tot2+=meta;
			}
			else {
				heap1[i]+=meta;
				tot1+=meta;
				tot2+=bigmeta;
			}
	}
	for (int i=10;i<100;i++) if (occ[i]==1) {
		if (tot1 < tot2) {
			heap1[i]++;
			tot1++;
			card1++;
		}
		else {
			tot2++;
			card2++;
		}
	}
	cout<<card1*card2<<endl;
	for (int i=0;i<2*n;i++) {
		if (heap1[val[i]]>0) {
			cout<<1<<" ";
			heap1[val[i]]--;
		}
		else cout<<2<<" ";
	}
	return 0;
}