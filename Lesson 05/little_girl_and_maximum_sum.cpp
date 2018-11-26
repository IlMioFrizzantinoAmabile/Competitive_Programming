/* The little girl loves the problems on array queries very much.
 * One day she came across a rather well-known problem: you've got an array of n elements (the elements of the array are indexed starting from 1);
 * also, there are q queries, each one is defined by a pair of integers li, ri (1 ≤ li ≤ ri ≤ n).
 * You need to find for each query the sum of elements of the array with indexes from li to ri, inclusive.
 * The little girl found the problem rather boring.
 * She decided to reorder the array elements before replying to the queries in a way that makes the sum of query replies maximum possible.
 * Your task is to find the value of this maximum sum.
 * Input:
 * The first line contains two space-separated integers n (1 ≤ n ≤ 2·105) and q (1 ≤ q ≤ 2·105) — the number of elements in the array and the number of queries, correspondingly.
 * The next line contains n space-separated integers ai (1 ≤ ai ≤ 2·105) — the array elements.
 * Each of the following q lines contains two space-separated integers li and ri (1 ≤ li ≤ ri ≤ n) — the i-th query.
 * Output:
 * In a single line print a single integer — the maximum sum of query replies after the array elements are reordered.
 * SOURCE: http://codeforces.com/problemset/problem/276/C?locale=en
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct compare{
	bool operator()(const int& a, const int& b){
		return a > b;
	}
};

int main(){
	int n,q;
	cin>>n>>q;
	vector<int> vet(n);
	for (int i=0;i<n;i++) cin>>vet[i];
	vector<ll> quer(n+1,0);
	for (int i=0;i<q;i++) {
		int l,r;
		cin>>l>>r;
		quer[l-1]++;
		quer[r]--;
	}
	for (int i=1;i<=n;i++) quer[i]+=quer[i-1];
	sort(vet.begin(),vet.end(),compare());
	sort(quer.begin(),--quer.end(),compare());
	ll max=0;
	for (int i=0;i<n;i++) max+=vet[i]*quer[i];
	cout<<max<<endl;
	return 0;
}
