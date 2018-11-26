#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll BIGGER=1000000000000000;

ll vec[2000000];
ll lazy[2000000];

void increase(int root, int value, int queryS, int queryE, int rangeS, int rangeE) {
	if (lazy[root]) {
		vec[root]+=lazy[root];
		if (rangeS!=rangeE) {
			lazy[2*root+1]+=lazy[root];
			lazy[2*root+2]+=lazy[root];
		}
		lazy[root]=0;
	}
	if (queryS>rangeE || queryE<rangeS) return;
	if (queryS<=rangeS && queryE>=rangeE) {
		vec[root]+=value;
		lazy[2*root+1]+=value;
		lazy[2*root+2]+=value;
		//cout<<"increase contenuto: "<<rangeS<<" - vec di "<<root<<" = "<<vec[root]<<endl;
		return;
	}
	//cout<<"increase : "<<rangeS<<" - "<<rangeE<<endl;
	int rangeM = (rangeS+rangeE)/2;
	increase(2*root+1, value, queryS, queryE, rangeS, rangeM);
	increase(2*root+2, value, queryS, queryE, rangeM+1, rangeE);
	vec[root]=min(vec[2*root+1],vec[2*root+2]);
} 

ll getMin(int root, int queryS, int queryE, int rangeS, int rangeE) {
	if (lazy[root]) {
		vec[root]+=lazy[root];
		if (rangeS!=rangeE) {
			lazy[2*root+1]+=lazy[root];
			lazy[2*root+2]+=lazy[root];
		}
		lazy[root]=0;
	}
	if (queryS>rangeE || queryE<rangeS) return BIGGER;
	if (queryS<=rangeS && queryE>=rangeE) return vec[root];
	int rangeM = (rangeS+rangeE)/2;
	ll leftMin = getMin(2*root+1, queryS, queryE, rangeS, rangeM);
	ll rightMin = getMin(2*root+2, queryS, queryE, rangeM+1, rangeE);
	return min(leftMin,rightMin);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin>>N;
	for (int i=0;i<N;i++) {
		int val;
		cin>>val;
		increase(0, val, i, i, 0, N-1);
		//for (int j=0;j<2*N-1;j++) cout<<vec[j]<<" "; cout<<endl;
		//for (int j=0;j<2*N-1;j++) cout<<lazy[j]<<" ";
		//cout<<endl<<"inserito "<<val<<endl<<endl;
	}
	int M;
	cin>>M;
	cin.ignore();
	while(M--) {
		char input[100];
		cin.getline(input, 100);
		int queryS, queryE, val;
		if(istringstream(input)>>queryS>>queryE>>val) {
			if (queryS<=queryE) increase(0, val, queryS, queryE, 0, N-1);
			else {
				increase(0, val, 0, queryE, 0, N-1);
				increase(0, val, queryS, N-1, 0, N-1);
			}
		}
		else {
			if (queryS<=queryE) cout<<getMin(0, queryS, queryE, 0, N-1)<<endl;
			else {
				ll leftMin = getMin(0, 0, queryE, 0, N-1);
				ll rightMin = getMin(0, queryS, N-1, 0, N-1);
				cout<<min(leftMin,rightMin)<<endl;
			}
		}
		//for (int j=0;j<2*N-1;j++) cout<<vec[j]<<" "; cout<<endl;
		//for (int j=0;j<2*N-1;j++) cout<<lazy[j]<<" ";
		//cout<<endl<<"------------"<<endl<<endl;
	}
	return 0;
}