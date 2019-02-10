/* PROBLEM
 * A magic number is a number formed by concatenation of numbers 1, 14 and 144. We can use each of these numbers any number of times.
 * Therefore 14144, 141414 and 1411 are magic numbers but 1444, 514 and 414 are not.
 * You're given a number. Determine if it is a magic number or not.
 * Input:
 * The first line of input contains an integer n. This number doesn't contain leading zeros.
 * Output:
 * Print "YES" if n is a magic number or print "NO" if it's not.
 * SOURCE: http://codeforces.com/problemset/problem/320/A
 *
 * SOLUTION
 * Banale aritmetica 
 * COMPLEXITY: O(log(n))
 */

#include<bits/stdc++.h>

using namespace std;

string isMagic(int n) {
	int rischio=0;
	while(n) {
		int cifra = n%10;
		if (cifra==1) rischio=0;
		else if (rischio==2) return "NO";
		else if (cifra==4) rischio++;
		else return "NO";
		n/=10;
	}
	if (rischio==0)	return "YES";
	else return "NO";
}

int main(){
	int n;
	cin>>n;
	cout<<isMagic(n);
	return 0;
}
