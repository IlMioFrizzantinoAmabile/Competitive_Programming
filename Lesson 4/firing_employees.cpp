#include<bits/stdc++.h>

using namespace std;

vector<bool> isPrime;

void prime_preprocessing(int n) {
	isPrime.reserve(n+1);
	isPrime[0] = isPrime[1] = false;
	for (int i=2; i<n; i++)	isPrime[i]=true;
	for (int p=2; p<= (int)sqrt(n); p++) if (isPrime[p]) {
			for (int molt=p; p*molt < n; molt++) isPrime[p*molt]=false;
	}
}

int main(){
	int T;
	cin>>T;
	for (int i=0;i<T;i++){
		int N;
		cin>>N;
		prime_preprocessing(2*N+1);
		vector<int> vec(N+1);
		vector<int> seniors(N+1,-1);
		for (int rank=1; rank<=N; rank++) {
			cin>>vec[rank];
			if (vec[rank]==0) seniors[rank]=0;
		}
		
		stack<int> s;
		for (int rank=1; rank<=N; rank++) {
			int tizio=rank;
			while (seniors[tizio]<0) {
				s.push(tizio);
				tizio = vec[tizio];
			}
			while (!s.empty()) {
				tizio = s.top();
				seniors[tizio] = 1+seniors[vec[tizio]];
				s.pop();
			}
		}
		
		int num_fired = 0;
		for (int rank=1; rank<=N; rank++) 
			if (seniors[rank] && isPrime[rank+seniors[rank]]) num_fired++;
		cout<<num_fired<<endl;
	}
	return 0;
}