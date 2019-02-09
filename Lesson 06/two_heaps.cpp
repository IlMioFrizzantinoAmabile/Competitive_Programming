/* PROBLEM
 * Valera has 2·n cubes, each cube contains an integer from 10 to 99. He arbitrarily chooses n cubes and puts them in the first heap.
 * The remaining cubes form the second heap. 
 * Valera decided to play with cubes. During the game he takes a cube from the first heap and writes down the number it has.
 * Then he takes a cube from the second heap and write out its two digits near two digits he had written (to the right of them). 
 * In the end he obtained a single fourdigit integer — the first two digits of it is written on the cube from the first heap,
 * and the second two digits of it is written on the second cube from the second heap.
 * Valera knows arithmetic very well. So, he can easily count the number of distinct fourdigit numbers he can get in the game.
 * The other question is: how to split cubes into two heaps so that this number (the number of distinct fourdigit integers Valera
 * can get) will be as large as possible?
 * Input:
 * The first line contains integer n. The second line contains 2·n space-separated integers denoting the numbers on the cubes.
 * Output:
 * In the first line print a single number — the maximum possible number of distinct four-digit numbers Valera can obtain.
 * In the second line print 2·n numbers bi (1 ≤ bi ≤ 2). The numbers mean: the i-th cube belongs to the bi-th heap in your division.
 * If there are multiple optimal ways to split the cubes into the heaps, print any of them.
 * SOURCE: http://codeforces.com/problemset/problem/353/B?locale=en
 *
 * SOLUTION
 * L'algoritmo memorizza le occorrenze di ciascun numero.
 * Computa i numeri che occorrono almeno 2 volte, assegnandone metà al primo heap e metà al secondo heap, in caso di disparità
 * ne assegna uno in più a quello che contiene meno elementi.
 * Computa i numeri che occorrono 1 volta, assegnandoli ogni volta all'heap che contiene meno elementi.
 * Questa strategia garantisce di massimizzare il risultato.
 * COMPLEXITY: O(n)
 */

#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> val(2*n);
	vector<int> occ(100,0);
	vector<int> heap1(100,0);
	for (int i=0;i<2*n;i++) {
		cin>>val[i];
		occ[val[i]]++;
	}
	int card1=0, card2=0, tot1=0, tot2=0;
	
	for (int i=10;i<100;i++) if (occ[i]>=2) {
			card1++;
			card2++;
			int meta = occ[i]/2;
			int bigmeta = occ[i]-meta;
			if (tot1 < tot2) {
				heap1[i]+=bigmeta;
				tot1+=bigmeta;
				tot2+=meta;
			}
			else {
				heap1[i]+=meta;
				tot1+=meta;
				tot2+=bigmeta;
			}
	}
	for (int i=10;i<100;i++) if (occ[i]==1) {
		if (tot1 < tot2) {
			heap1[i]++;
			tot1++;
			card1++;
		}
		else {
			tot2++;
			card2++;
		}
	}
	cout<<card1*card2<<endl;
	for (int i=0;i<2*n;i++) {
		if (heap1[val[i]]>0) {
			cout<<1<<" ";
			heap1[val[i]]--;
		}
		else cout<<2<<" ";
	}
	return 0;
}
