/* PROBLEM
 * Given an array A of N non-negative integers representing height of blocks at index i as Ai, where the width of each block is 1.
 * Compute how much water can be trapped in between blocks after raining.
 * Input:
 * The first line of input contains an integer T denoting the number of test cases.
 * The description of T test cases follows. Each test case contains an integer N followed by N numbers to be stored in array.
 * Output:
 * Print the total unit of water trapped in between the blocks.
 * SOURCE: https://practice.geeksforgeeks.org/problems/trapping-rain-water/0
 *
 * SOLUTION
 * L'algoritmo tiene in memoria due puntatori (sx,dx) che delimitano un sotto-intervallo dell'array, all'inizio tutto.
 * Ad ogni passo questo intervallo viene stretto, dal lato con altezza minore, aggiungendo acqua finché trova un muro più alto.
 * COMPLEXITY: O(n)
 */

#include<bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin>>T;
	for (int j=0;j<T;j++) {
		int N;
		cin>>N;
		vector<int> height(N);
		for (int i=0;i<N;i++)	cin>>height[i];
		vector<int>::iterator	sx=height.begin(),dx=height.end();
		dx--;
		int water=0;
		while(sx!=dx) {
			vector<int>::iterator it;
			if (*sx<=*dx) {
				for (it=sx; *it<=*sx && it!=dx; it++)	water+= *sx-*it;
				sx=it;				
			}
			else {
				for (it=dx; *it<=*dx; it--) water+= *dx-*it;
				dx=it;
			}
		}
		cout<<water<<endl;
	}
	return 0;
}
