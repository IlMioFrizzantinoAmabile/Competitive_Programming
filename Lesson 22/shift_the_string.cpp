/* You are given two strings A and B of the same length. 
 * Each string contains N Lower case Latin character (from 'a' to 'z'). 
 * A shift operation will remove the first character of a string and add the same character at the end of that string.
 * For example after you perform a shift operation on a string 'abcd', the new string will be 'bcda'.
 * If you perform this operation two times, the new string will be 'cdab'. 
 * You need to use some (maybe none) shift operations on the string B to maximize the length of the longest common prefix of A and B. 
 * If more than one result can be found pick the one that use smallest number of shift operations.
 * Input:
 * The first line of the input contains a single integer N. The second and the third lind contains the string A and B respectively.
 * Output:
 * Contains a single integer which is the number of shift operations.
 * SOURCE: https://www.codechef.com/problems/TASHIFT
 */

#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin>>N;
	string A,B;
	cin>>A>>B;
	
	int lps[1000001]; //longest prefix suffix dei prefissi della stringa A
	lps[0]=0;
	int leng=0, i=1;
	while(i < N) {
		if(A[i] == A[leng]) {
			leng++;
			i++;
			lps[i] = leng;
		}
		else if(leng > 0) leng = lps[leng];
		else i++;
	}
	
	int shift = 0;
	int mx = 0;
	int argmx = 0;
	i=0;
	while(i<N && shift<N) {
		if(A[i] == B[(i+shift)%N]) {
			i++;
			if(mx < i) {
				mx=i;
				argmx=shift;
			}
		}
		else if(i > 0) {
			shift += i - lps[i];
			i = lps[i];
		}
		else shift++;
	}
	cout<<argmx<<endl;
	
	return 0;
}
