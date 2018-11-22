#include<bits/stdc++.h>

using namespace std;

#define MEGACITY 1000000

struct city {
	int p;
	double r;
};

struct compare{
	bool operator()(const city& a, const city& b){
		return a.r < b.r;
	}
};

int main(){
	cout<<setprecision(7)<<fixed;
	int n,s;
	cin>>n>>s;
	vector<city> world(n);
	for (int i=0;i<n;i++) {
		int x,y,p;
		cin>>x>>y>>p;
		world[i].p = p;
		world[i].r = sqrt(x*x+y*y);
	}
	sort(world.begin(),world.end(),compare());
	int i=0;
	while(s<MEGACITY && i<n) s+=world[i++].p;
	if (s>=MEGACITY) cout<<world[--i].r<<endl;
	else cout<<-1<<endl;
	return 0;
}