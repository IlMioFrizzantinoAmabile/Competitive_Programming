/* An array of positive integers a1, a2, ..., an is given. 
 * Let us consider its arbitrary subarray al, al + 1..., ar, where 1 ≤ l ≤ r ≤ n.
 * For every positive integer s denote by Ks the number of occurrences of s into the subarray.
 * We call the power of the subarray the sum of products Ks·Ks·s for every positive integer s.
 * The sum contains only finite number of nonzero summands as the number of different values in the array is indeed finite.
 * The task is to calculate the power of t given subarrays.
 * Input:
 * First line contains two integers n and t, the array length and the number of queries correspondingly.
 * Second line contains n positive integers ai, the elements of the array.
 * Next t lines contain two positive integers l, r (1 ≤ l ≤ r ≤ n), the indices of the left and the right ends of the corresponding subarray.
 * Output:
 * Print t lines, the i-th line of the output should contain single positive integer, the power of the i-th query subarray.
 * SOURCE: http://codeforces.com/contest/86/problem/D
 */

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

double sqrtN;
ll answer;
int occ[1000001];

struct range {
	int left,right;
	int index;
	ll answer;
};

struct compMOs{
	bool operator()(const range& a, const range& b){
		int blockA = (int) a.left/sqrtN;
		int blockB = (int) b.left/sqrtN;
		if (blockA<blockB) return true;
		else if (blockA>blockB) return false;
		else return a.right < b.right;
	}
};
struct comp{
	bool operator()(const range& a, const range& b){
		return a.index < b.index;
	}
};

void add(int i, vector<int>& vet) {
	answer+=vet[i]*(2*occ[vet[i]]+1);
	occ[vet[i]]++;
}
void remove(int i, vector<int>& vet) {
	occ[vet[i]]--;
	answer-=vet[i]*(2*occ[vet[i]]+1);
}
	
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,t;
	cin>>n>>t;
	sqrtN=sqrt(n);
	vector<int> vet(n);
	vector<range> query(t);
	for (int i=1;i<=n;i++) cin>>vet[i];
	for (int i=0;i<t;i++) {
		cin>>query[i].left>>query[i].right;
		query[i].index = i;
	}
	sort(query.begin(),query.end(),compMOs());
	int currLeft=0,currRight=0;
	for (vector<range>::iterator currQuery = query.begin(); currQuery!=query.end(); currQuery++) {
		while (currLeft < currQuery->left) {
			remove(currLeft,vet);
			currLeft++;
		}
		while (currLeft > currQuery->left) {
			currLeft--;
			add(currLeft,vet);
		}
		while (currRight < currQuery->right) {
			currRight++;
			add(currRight,vet);
		}
		while (currRight > currQuery->right) {
			remove(currRight,vet);
			currRight--;
		}
		currQuery->answer = answer;
	}
	sort(query.begin(),query.end(),comp());
	for (int i=0;i<t;i++) cout<<query[i].answer<<endl;
	return 0;
}
