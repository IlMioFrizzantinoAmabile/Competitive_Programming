#include<bits/stdc++.h>

using namespace std;

struct meet{
	int inizio,fine;
	int index;
};

struct comp{
	bool operator()(const meet& a, const meet& b){
		return a.fine < b.fine;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		int N;
		cin>>N;
		vector<meet> meeting(N);
		for (int i=0;i<N;i++) meeting[i].index = i;
		for (int i=0;i<N;i++) cin>>meeting[i].inizio;
		for (int i=0;i<N;i++) cin>>meeting[i].fine;
		sort(meeting.begin(),meeting.end(),comp());
		int fine=-1;
		vector<meet>::iterator it;
		for (it=meeting.begin(); it!=meeting.end(); it++) if (it->inizio > fine) {
				fine = it->fine;
				cout<<it->index<<" ";
		}
		cout<<endl;
	}
	return 0;
}