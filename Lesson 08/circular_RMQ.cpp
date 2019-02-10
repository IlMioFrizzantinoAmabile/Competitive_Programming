/* PROBLEM
 * You are given circular array a0, a1, ..., an - 1. There are two types of operations with it:
 * - inc(lf, rg, v) — this operation increases each element on the segment [lf, rg] (inclusively) by v;
 * - rmq(lf, rg) — this operation returns minimal value on the segment [lf, rg] (inclusively).
 * Assume segments to be circular, so if n = 5 and lf = 3, rg = 1, it means the index sequence: 3, 4, 0, 1.
 * The task is to process given sequence of operations.
 * Input:
 * The first line contains integer n (1 ≤ n ≤ 200000).
 * The next line contains initial state of the array: a0, a1, ..., an - 1, ai are integer.
 * The third line contains integer m (0 ≤ m ≤ 200000), m — the number of operartons.
 * Next m lines contain one operation each. 
 * If line contains two integer lf, rg it means rmq operation,
 * if contains three integers lf, rg, v it means inc operation.
 * Output:
 * For each rmq operation write result for it.
 * SOURCE: http://codeforces.com/problemset/problem/52/C
 *
 * SOLUTION
 * L'algoritmo utilizza la ben nota struttura dati del Range Tree, che in questo caso chiaramente memorizza il minimo dei sottointervalli.
 * Viene qui implementato in versione Lazy, che non aggiorna ogni singolo elemento ad ogni operazione "increase", ma si tiene in memoria
 * in un albero analogo (lazy[]) gli aggiornamenti da fare. Questi vengono effettivamente fatti solo quando (e se) serviranno davvero.
 * Il Range Tree non comprende la funzionalità dell'array circolare, questa si ottiene facilmente lanciando due query.
 * COMPLEXITY: O(n+m*log(n))
 */

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll BIGGER=1000000000000000;

ll vec[2000000];
ll lazy[2000000];

void increase(int root, int value, int queryS, int queryE, int rangeS, int rangeE) {
	if (lazy[root]) {
		vec[root]+=lazy[root];
		if (rangeS!=rangeE) {
			lazy[2*root+1]+=lazy[root];
			lazy[2*root+2]+=lazy[root];
		}
		lazy[root]=0;
	}
	if (queryS>rangeE || queryE<rangeS) return;
	if (queryS<=rangeS && queryE>=rangeE) {
		vec[root]+=value;
		lazy[2*root+1]+=value;
		lazy[2*root+2]+=value;
		return;
	}
	int rangeM = (rangeS+rangeE)/2;
	increase(2*root+1, value, queryS, queryE, rangeS, rangeM);
	increase(2*root+2, value, queryS, queryE, rangeM+1, rangeE);
	vec[root]=min(vec[2*root+1],vec[2*root+2]);
} 

ll getMin(int root, int queryS, int queryE, int rangeS, int rangeE) {
	if (lazy[root]) {
		vec[root]+=lazy[root];
		if (rangeS!=rangeE) {
			lazy[2*root+1]+=lazy[root];
			lazy[2*root+2]+=lazy[root];
		}
		lazy[root]=0;
	}
	if (queryS>rangeE || queryE<rangeS) return BIGGER;
	if (queryS<=rangeS && queryE>=rangeE) return vec[root];
	int rangeM = (rangeS+rangeE)/2;
	ll leftMin = getMin(2*root+1, queryS, queryE, rangeS, rangeM);
	ll rightMin = getMin(2*root+2, queryS, queryE, rangeM+1, rangeE);
	return min(leftMin,rightMin);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin>>N;
	for (int i=0;i<N;i++) {
		int val;
		cin>>val;
		increase(0, val, i, i, 0, N-1);
	}
	int M;
	cin>>M;
	cin.ignore();
	while(M--) {
		char input[100];
		cin.getline(input, 100);
		int queryS, queryE, val;
		if(istringstream(input)>>queryS>>queryE>>val) {
			if (queryS<=queryE) increase(0, val, queryS, queryE, 0, N-1);
			else {
				increase(0, val, 0, queryE, 0, N-1);
				increase(0, val, queryS, N-1, 0, N-1);
			}
		}
		else {
			if (queryS<=queryE) cout<<getMin(0, queryS, queryE, 0, N-1)<<endl;
			else {
				ll leftMin = getMin(0, 0, queryE, 0, N-1);
				ll rightMin = getMin(0, queryS, N-1, 0, N-1);
				cout<<min(leftMin,rightMin)<<endl;
			}
		}
	}
	return 0;
}
