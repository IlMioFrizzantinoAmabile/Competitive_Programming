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

int remap(vector<int>& vet) {
	int n=vet.size();
	vector<int> tmp(n);
	copy(vet.begin(),vet.end(),tmp.begin());
	sort(tmp.begin(),tmp.end());
	map<int,int> rank;
	int r=0,i=0;
	while (i<n) {
		rank.insert(make_pair(tmp[i],r++));
		while (tmp[i]==tmp[++i] && i<n) {};
	}
	for (int i=0;i<n;i++)	vet[i] = rank[vet[i]];
	return r;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<int> vet(n),tmp(n);
	for (int i=0;i<n;i++)	cin>>vet[i];
	int cardinalita = remap(vet);
	int counter[cardinalita], suffixCounter[n];
	for (int i=0;i<cardinalita;i++)	counter[i]=0;
	for (int i=0;i<n;i++)			suffixCounter[i]=0;
	fenwick_tree BIT(n);
	for (int i=n-1;i>=0;i--) {
		counter[vet[i]]++;
		suffixCounter[i]=counter[vet[i]];
		BIT.update(suffixCounter[i],1);
	}
	for (int i=0;i<cardinalita;i++)	counter[i]=0;
	ll answer=0;
	for (int i=0;i<n;i++) {
		counter[vet[i]]++;
		BIT.update(suffixCounter[i],-1);
		answer+=BIT.sum(counter[vet[i]]-1);
	}
	cout<<answer<<endl;
	return 0;
}