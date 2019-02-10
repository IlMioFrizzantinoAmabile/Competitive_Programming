/* PROBLEM
 * Wilbur the pig is tinkering with arrays again. He has the array a1, a2, ..., an initially consisting of n zeros.
 * At one step, he can choose any index i and either add 1 to all elements ai, ai + 1, ... , an or subtract 1 from
 * all elements ai, ai + 1, ..., an. His goal is to end up with the array b1, b2, ..., bn.
 * Of course, Wilbur wants to achieve this goal in the minimum number of steps and asks you to compute this value.
 * Input:
 * The first line of the input contains a single integer n, the length of the array ai. 
 * Initially ai = 0 for every position i, so this array is not given in the input.
 * The second line of the input contains n integers b1, b2, ..., bn.
 * Output:
 * Print the minimum number of steps that Wilbur needs to make in order to achieve ai = bi for all i.
 * SOURCE: http://codeforces.com/problemset/problem/596/B
 *
 * SOLUTION
 * La soluzione è il valore assoluto del primo elemento più la somma dei valori assoluti delle differenze degli elementi consecutivi.
 * COMPLEXITY: O(n)
 */

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int abs(int x) {
	return x>0 ? x : -x;
}

int main(){
	int n;
	cin>>n;
	ll tot=0;
	int last=0,now;
	while(n--) {
		cin>>now;
		tot+=abs(last-now);
		last=now;
	}
	cout<<tot<<endl;
	return 0;
}
