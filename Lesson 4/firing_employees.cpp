/* Mr. Alfred is the founder of FooLand Constructions.
 * He always maintains a ‘Black list’ of potential employees which can be fired at any moment without any prior notice.
 * This company has N employees (including Mr. Alfred), and each employee is assigned a rank (1 <= rank <= N) at the time of joining the company. Any person can have any rank from 1 to N. No two persons have the same rank. 
 * The company has a hierarchically organized management. Each employee has one immediate senior but can have any number of seniors.
 * If a person A is the senior of B and B is senior of C, this implies that A is also a senior of C. Note that Mr. Alfred has no senior to him.
 * Mr. Alfred has a strange and unfair way of evaluating an employee’s performance. Those employees the sum of whose rank and the number of his/her seniors is a prime number is put up on the ‘Black list’.
 * The task is to find out the number of ‘Black listed’ employees.
 * Note: The list won’t contain Mr. Alfred’s name as he is the founder of the company and the list is managed by him!
 * Input:
 * The first line of input consists of a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line contains a single integer N as described in the problem statement.
 * The next line contains N integers. The ith integer (1 <= i <= N) represents the rank of the immediate senior of the ith employee (i.e. the employee with rank = i). If the ith integer is 0, it represents that employee with rank = i is Mr. Alfred as he has no superior.
 * Output:
 * For each test case, print in a new line the number of ‘Black listed’ employees.
 * SOURCE: https://practice.geeksforgeeks.org/problems/firing-employees/0
 */

#include<bits/stdc++.h>

using namespace std;

vector<bool> isPrime;

void prime_preprocessing(int n) {
	isPrime.reserve(n+1);
	isPrime[0] = isPrime[1] = false;
	for (int i=2; i<n; i++)	isPrime[i]=true;
	for (int p=2; p<= (int)sqrt(n); p++) if (isPrime[p]) {
			for (int molt=p; p*molt < n; molt++) isPrime[p*molt]=false;
	}
}

int main(){
	int T;
	cin>>T;
	for (int i=0;i<T;i++){
		int N;
		cin>>N;
		prime_preprocessing(2*N+1);
		vector<int> vec(N+1);
		vector<int> seniors(N+1,-1);
		for (int rank=1; rank<=N; rank++) {
			cin>>vec[rank];
			if (vec[rank]==0) seniors[rank]=0;
		}
		
		stack<int> s;
		for (int rank=1; rank<=N; rank++) {
			int tizio=rank;
			while (seniors[tizio]<0) {
				s.push(tizio);
				tizio = vec[tizio];
			}
			while (!s.empty()) {
				tizio = s.top();
				seniors[tizio] = 1+seniors[vec[tizio]];
				s.pop();
			}
		}
		
		int num_fired = 0;
		for (int rank=1; rank<=N; rank++) 
			if (seniors[rank] && isPrime[rank+seniors[rank]]) num_fired++;
		cout<<num_fired<<endl;
	}
	return 0;
}
