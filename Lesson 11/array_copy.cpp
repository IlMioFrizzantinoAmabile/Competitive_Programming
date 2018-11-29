#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct fenwick_tree {
	vector<int> BIT;
	fenwick_tree (int n) : BIT(n+1,0) {}
	int sum(int pos) {
		int tot=0;
		pos++;
		while (pos>0) {
			tot+=BIT[pos];
			pos -= pos & -pos;
		}
		return tot;
	}
	void update(int pos, int val) {
		pos++;
		while (pos<=BIT.size()) {
			BIT[pos]+=val;
			pos += pos & -pos;
		}
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> A(n),B(n);
	for (int i=0;i<n;i++)	cin>>A[i];
	for (int i=0;i<n;i++)	cin>>B[i];
	fenwick_tree BIT(n+1);
	fenwick_tree BITbool(n+1);
	for (int i=0;i<m;i++) {
		int type;
		cin>>type;
		if (type==1) {
			int x,y,k;
			cin>>x>>y>>k;
			BIT.update(y, x-y);
			BIT.update(y+k+1, x-y);
			BITbool.update(y,1);
			BITbool.update(y+k+1,-1);
		}
		if (type==2) {
			int index;
			cin>>index;
			if (BITbool.sum(index))	cout<<A[index+BIT.sum(index)]<<endl;
			else cout<<B[index];
		}
	}
	return 0;
}