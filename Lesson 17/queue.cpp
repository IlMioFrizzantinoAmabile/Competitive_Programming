#include<bits/stdc++.h>

using namespace std;

struct person {
	string name;
	int davanti;
	int h;
	int posizione;
};
struct compDavanti {
	bool operator()(const person& a, const person& b) {
		return a.davanti < b.davanti;
	}
};
struct compPosizione {
	bool operator()(const person& a, const person& b) {
		return a.posizione < b.posizione;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	person guy[3001];
	for (int i=0;i<n;i++)	{
		cin>>guy[i].name>>guy[i].davanti;
		guy[i].posizione=i;
	}
	
	sort(guy,guy+n,compDavanti());
	
	bool impossible=false;
	int inseriti=0;
	vector<int> ordine;
	for (int i=0;i<n and !impossible;i++) {
		if (guy[i].davanti > inseriti) impossible=true;
		else {
			ordine.insert(ordine.begin()+inseriti-guy[i].davanti , i);
			inseriti++;
		}
		
	}
	if (impossible)	cout<<-1<<endl;
	else {
		for (int i=0;i<n;i++)	guy[ordine[i]].h = i+1;
		for (int i=0;i<n;i++)	cout<<guy[i].name<<" "<<guy[i].h<<endl;
	}
	
	return 0;
}