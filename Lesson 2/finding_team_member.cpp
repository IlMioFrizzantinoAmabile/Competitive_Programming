#include<bits/stdc++.h>

using namespace std;

struct pairr{
	int strenght;
	int first;
	int second;
};
struct compare{
	bool operator()(const pairr& a, const pairr& b){
		return a.strenght > b.strenght;
	}
};

int main(){
	int N;
	cin>>N;
	vector<pairr> v(2*N*(N-1));
	for (int i=1;i<2*N;i++) for(int j=0;j<i;j++) {
		int s;
		cin>>s;
		pairr nuovo = {s,j,i};
		v.push_back(nuovo);
	}
	sort(v.begin(),v.end(),compare());
	vector<int> team(2*N, -1);
	for (vector<pairr>::iterator it=v.begin(); it!=v.end(); it++) {
		if (team[it->first]<0 && team[it->second]<0) {
			team[it->first] = it->second;
			team[it->second] = it->first;
		}
	}
	for (vector<int>::iterator it=team.begin(); it!=team.end(); it++) {
		cout<<*it+1<<" ";
	}
	cout<<endl;
	return 0;
}