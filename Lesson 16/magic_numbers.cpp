#include<bits/stdc++.h>

using namespace std;

string isMagic(int n) {
	int rischio=0;
	while(n) {
		int cifra = n%10;
		if (cifra==1) rischio=0;
		else if (rischio==2) return "NO";
		else if (cifra==4) rischio++;
		else return "NO";
		n/=10;
	}
	if (rischio==0)	return "YES";
	else return "NO";
}

int main(){
	int n;
	cin>>n;
	cout<<isMagic(n);
	return 0;
}