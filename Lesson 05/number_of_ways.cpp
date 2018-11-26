/* You've got array a[1], a[2], ..., a[n], consisting of n integers.
 * Count the number of ways to split all the elements of the array into three contiguous parts
 * so that the sum of elements in each part is the same.
 * Input:
 * The first line contains integer n (1 ≤ n ≤ 5·105), showing how many numbers are in the array.
 * The second line contains n integers a[1], a[2], ..., a[n] (|a[i]| ≤  109) — the elements of array a.
 * Output:
 * Print a single integer — the number of ways to split the array into three parts with the same sum.
 * SOURCE: http://codeforces.com/problemset/problem/466/C?locale=en
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin>>n;
	vector<int> vet(n);
	ll sum=0,tot=0;
	for (int i=0;i<n;i++) {
		cin>>vet[i];
		sum+=vet[i];
	}
	if (sum%3!=0) cout<<0<<endl;
	else {
		sum/=3;
		ll provv=0;
		vector<int> left(n,0);
		for (int i=0;i<n;i++) {
			provv+=vet[i];
			if (provv==sum) left[i]=1;
		}
		for (int i=1;i<n;i++) {
			left[i]+=left[i-1];
		}
		provv=0;
		for (int i=n-1;i>1;i--) {
			provv+=vet[i];
			if (provv==sum) tot+=left[i-2];
		}
		cout<<tot<<endl;
	}
	return 0;
}
