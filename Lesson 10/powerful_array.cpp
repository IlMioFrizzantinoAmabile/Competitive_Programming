#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

double sqrtN;
ll answer;
int occ[1000001];

struct range {
	int left,right;
	int index;
	ll answer;
};

struct compMOs{
	bool operator()(const range& a, const range& b){
		int blockA = (int) a.left/sqrtN;
		int blockB = (int) b.left/sqrtN;
		if (blockA<blockB) return true;
		else if (blockA>blockB) return false;
		else return a.right < b.right;
	}
};
struct comp{
	bool operator()(const range& a, const range& b){
		return a.index < b.index;
	}
};

void add(int i, vector<int>& vet) {
	answer+=vet[i]*(2*occ[vet[i]]+1);
	occ[vet[i]]++;
}
void remove(int i, vector<int>& vet) {
	occ[vet[i]]--;
	answer-=vet[i]*(2*occ[vet[i]]+1);
}
	
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,t;
	cin>>n>>t;
	sqrtN=sqrt(n);
	vector<int> vet(n);
	vector<range> query(t);
	for (int i=1;i<=n;i++) cin>>vet[i];
	for (int i=0;i<t;i++) {
		cin>>query[i].left>>query[i].right;
		query[i].index = i;
	}
	sort(query.begin(),query.end(),compMOs());
	int currLeft=0,currRight=0;
	for (vector<range>::iterator currQuery = query.begin(); currQuery!=query.end(); currQuery++) {
		while (currLeft < currQuery->left) {
			remove(currLeft,vet);
			currLeft++;
		}
		while (currLeft > currQuery->left) {
			currLeft--;
			add(currLeft,vet);
		}
		while (currRight < currQuery->right) {
			currRight++;
			add(currRight,vet);
		}
		while (currRight > currQuery->right) {
			remove(currRight,vet);
			currRight--;
		}
		currQuery->answer = answer;
	}
	sort(query.begin(),query.end(),comp());
	for (int i=0;i<t;i++) cout<<query[i].answer<<endl;
	return 0;
}