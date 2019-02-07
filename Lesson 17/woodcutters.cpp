#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int x[10001],h[10001];
	for (int i=0;i<n;i++) cin>>x[i]>>h[i];
	int rightmost=-1000000000,tot=1;
	for (int i=0;i<n-1;i++) {
		if (x[i]-h[i] > rightmost) {
			//fell left
			tot++;
			rightmost = x[i];
		}
		else if (x[i]+h[i] < x[i+1]) {
			//fell right
			tot++;
			rightmost = x[i]+h[i];
		}
		else rightmost = x[i];
	}
	cout>>tot>>endl;
}
//This program runs in linear time 
//BUT this is NOT enough to pass codeforces tests.
//So i wrote the fastest possibile version of the program, in C.

/*
#include<stdio.h>

int nextInt() {		//faster version of scanf
	int n=0,negative=0,c=getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') {
		negative = 1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		n = 10 * n + c - '0';
		c = getchar();
	}
	if (negative) return -n;
	else return n;
}

int main(){
	int n=nextInt(),i;
	int oldX=nextInt(),oldH;
	int newX;
	int rightmost=-1000000000,tot=1;
	for (i=1;i<n;i++) {
		oldH=nextInt();
		newX=nextInt();
		if (oldX-oldH > rightmost) {
			//fell left
			tot++;
			rightmost = oldX;
		}
		else if (oldX+oldH < newX) {
			//fell right
			tot++;
			rightmost = oldX+oldH;
		}
		else rightmost = oldX;
		oldX=newX;
	}
	printf("%d",tot);
}
*/

