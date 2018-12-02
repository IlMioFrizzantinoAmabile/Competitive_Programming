/* Kevin has just recevied his disappointing results on the USA Identification of Cows Olympiad (USAICO) in the form of a binary 
 * string of length n. Each character of Kevin's string represents Kevin's score on one of the n questions of the olympiad: 
 * '1' for a correctly identified cow and '0' otherwise.
 * However, all is not lost. Kevin is a big proponent of alternative thinking and believes that his score, instead of being the sum
 * of his points, should be the length of the longest alternating subsequence of his string. Here, we define an alternating subsequence
 * of a string as a not-necessarily contiguous subsequence where no two consecutive elements are equal.
 * Kevin, being the sneaky little puffball that he is, is willing to hack into the USAICO databases to improve his score.
 * In order to be subtle, he decides that he will flip exactly one substring—that is, take a contiguous non-empty substring of his
 * score and change all '0's in that substring to '1's and vice versa. After such an operation, Kevin wants to know the length of
 * the longest possible alternating subsequence that his string could have.
 * Input:
 * The first line contains the number of questions on the olympiad n (1 ≤ n ≤ 100 000).
 * The following line contains a binary string of length n representing Kevin's results on the USAICO.
 * Output:
 * Print a single integer, the length of the longest possible alternating subsequence that Kevin can create in his string after flipping
 * a single substring.
 * SOURCE: http://codeforces.com/problemset/problem/603/A
 */

#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d\n",&n);
	int tot=3;
	char last,now;
	last=getchar();
	for (int i=1;i<n;i++) {
		now=getchar();
		if (now!=last) tot++;
		last=now;
	}
	printf("%d\n",min(tot,n));
	return 0;
}
