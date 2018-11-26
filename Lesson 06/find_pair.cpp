/* You've got another problem dealing with arrays. Let's consider an arbitrary sequence containing n (not necessarily different)
 * integers a1, a2, ..., an. We are interested in all possible pairs of numbers (ai, aj), (1 ≤ i, j ≤ n). In other words, let's
 * consider all n2 pairs of numbers, picked from the given array.
 * Let's sort all resulting pairs lexicographically by non-decreasing. Let us remind you that pair (p1, q1) is lexicographically
 * less than pair (p2, q2) only if either p1 < p2, or p1 = p2 and q1 < q2.
 * The task is to find the k-th pair in the ordered list of all possible pairs of the array you've been given.
 * Input:
 * The first line contains two integers n and k. The second line contains the array containing n integers a1, a2, ..., an.
 * The numbers in the array can coincide. All numbers are separated with spaces.
 * Output:
 * In the single line print two numbers — the sought k-th pair.
 * SOURCE: http://codeforces.com/problemset/problem/160/C?locale=en
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct compare{
	bool operator()(const int& a, const int& b){
		return a < b;
	}
};

int main(){
	ll n,k;
	cin>>n>>k;
	vector<int> vet(n);
	for (int i=0;i<n;i++) cin>>vet[i];
	sort(vet.begin(),vet.end(),compare());
	vector<int> same(n,1);
	bool rep=false;
	for (int i=1;i<n;i++) if (vet[i]==vet[i-1]) {
		rep=true;
		same[i]+=same[i-1];
	}
	int first = (k-1)/n;
	int i=first;
	int position = same[i];
	if (i<n-1) while (same[i]+1==same[++i]) {}
	else i++;
	int repetition = same[--i];
	int second = (k-1)%n;
	second = ((position-1)*n+second)/repetition;
	cout<<vet[first]<<" "<<vet[second]<<endl;
	return 0;
}
