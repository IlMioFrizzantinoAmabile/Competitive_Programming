/* PROBLEM
 * Little Susie listens to fairy tales before bed every day. 
 * Today's fairy tale was about wood cutters and the little girl immediately started imagining the choppers cutting wood.
 * She imagined the situation that is described below.
 * There are n trees located along the road at points with coordinates x1, x2, ..., xn. Each tree has its height hi.
 * Woodcutters can cut down a tree and fell it to the left or to the right.
 * After that it occupies one of the segments [xi - hi, xi] or [xi;xi + hi].
 * The tree that is not cut down occupies a single point with coordinate xi.
 * Woodcutters can fell a tree if the segment to be occupied by the fallen tree doesn't contain any occupied point.
 * The woodcutters want to process as many trees as possible, so Susie wonders, what is the maximum number of trees to fell. 
 * Input:
 * The first line contains integer n, the number of trees.
 * Next n lines contain pairs of integers xi, hi, the coordinate and the height of the і-th tree. 
 * The pairs are given in the order of ascending xi. No two trees are located at the point with the same coordinate.
 * Output:
 * Print a single number, the maximum number of trees that you can cut down by the given rules.
 * SOURCE: http://codeforces.com/contest/545/problem/C
 *
 * SOLUTION
 * L'algoritmo greedy processa gli alberi in ordine, li fa cadere a sinistra se può, altrimenti a destra, se può.
 * COMPLEXITY: O(n)
 */

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

