#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin>>N;
	string A,B;
	cin>>A>>B;
	
	int lps[1000001]; //longest prefix suffix dei prefissi della stringa A
	lps[0]=0;
	int leng=0, i=1;
	while(i < N) {
		if(A[i] == A[leng]) {
			leng++;
			i++;
			lps[i] = leng;
		}
		else if(leng > 0) leng = lps[leng];
		else i++;
	}
	
	int shift = 0;
	int mx = 0;
	int argmx = 0;
	i=0;
	while(i<N && shift<N) {
		if(A[i] == B[(i+shift)%N]) {
			i++;
			if(mx < i) {
				mx=i;
				argmx=shift;
			}
		}
		else if(i > 0) {
			shift += i - lps[i];
			i = lps[i];
		}
		else shift++;
	}
	cout<<argmx<<endl;
	
	return 0;
}