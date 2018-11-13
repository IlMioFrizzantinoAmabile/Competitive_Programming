#include<bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin>>T;
	for (int j=0;j<T;j++) {
		int N;
		cin>>N;
		vector<int> height(N);
		for (int i=0;i<N;i++)	cin>>height[i];
		vector<int>::iterator	sx=height.begin(),dx=height.end();
		dx--;
		int water=0;
		while(sx!=dx) {
			vector<int>::iterator it;
			if (*sx<=*dx) {
				for (it=sx; *it<=*sx && it!=dx; it++)	water+= *sx-*it;
				sx=it;				
			}
			else {
				for (it=dx; *it<=*dx; it--) water+= *dx-*it;
				dx=it;
			}
		}
		cout<<water<<endl;
	}
	return 0;
}