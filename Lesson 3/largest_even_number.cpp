/* In this problem there is a number P (always a whole number) with N digits.
 * We ask what is the largest possible even number formed by rearranging this N digit number.
 * For example consider number 1324, after rearranging the digits the largest even number possible is 4312.
 * Note: In case the number does not contain any even digit then output the largest odd number possible.
 * Input:
 * The first line of input will contain an integer T which is the no. of test cases. Each of the next T lines will contain a number P.
 * Output:
 * For each test case in a new line print the required result.
 * SOURCE: https://practice.geeksforgeeks.org/problems/largest-even-number/0
 */

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int T;
	cin>>T;
	char c=getchar();
	for (int i=0;i<T;i++){
		vector<int> digits(10,0);
		while ((c=getchar())>='0' && c<='9')	digits[c-'0']++;
		int evenDig = -1;
		for (int j=0; j<10 && evenDig<0; j=j+2)	if (digits[j]>0) {
			evenDig=j;
			digits[j]--;		
		}
		for (int j=9; j>=0; j--) while (digits[j]) {
				cout<<j;
				digits[j]--;
		}
		if (evenDig>=0)	cout<<evenDig;
		cout<<endl;
	}
	return 0;
}
