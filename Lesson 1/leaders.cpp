#include<bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin>>T;
	for (int i=0;i<T;i++){
		int N;
		cin>>N;
		vector<int> num(N);
		for (int j=0;j<N;j++) cin>>num[j];
		int max=num[N-1];
		list<int> leaders;
		for(int j=N-1;j>=0;j--){
			if (num[j]>=max)	{
				leaders.push_front(num[j]);
				max=num[j];
			}
		}
		for(list<int>::iterator it = leaders.begin(); it!=leaders.end(); it++) cout<<*it<<" ";
		cout<<endl;
	}
	return 0;
}