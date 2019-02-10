/* PROBLEM
 * There is one meeting room in Flipkart.
 * There are n meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.
 * What is the maximum number of meetings that can be accommodated in the meeting room ?
 * Input:
 * The first line of input consists number of the test cases. The description of T test cases is as follows:
 * The first line consists of the size of the array,
 * second line has the array containing the starting time of all the meetings each separated by a space, i.e., S[i]. 
 * And the third line has the array containing the finishing time of all the meetings each separated by a space, i.e., F[i].
 * Output:
 * In each separate line print the order in which the meetings take place separated by a space.
 * SOURCE: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0
 *
 * SOLUTION
 * L'algoritmo sorta i meeting per finishing time crescente e poi li processa dall'inizio con strategia greedy.
 * COMPLEXITY: O(n*log(n))
 */

#include<bits/stdc++.h>

using namespace std;

struct meet{
	int inizio,fine;
	int index;
};

struct comp{
	bool operator()(const meet& a, const meet& b){
		return a.fine < b.fine;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		int N;
		cin>>N;
		vector<meet> meeting(N);
		for (int i=0;i<N;i++) meeting[i].index = i;
		for (int i=0;i<N;i++) cin>>meeting[i].inizio;
		for (int i=0;i<N;i++) cin>>meeting[i].fine;
		sort(meeting.begin(),meeting.end(),comp());
		int fine=-1;
		vector<meet>::iterator it;
		for (it=meeting.begin(); it!=meeting.end(); it++) if (it->inizio > fine) {
				fine = it->fine;
				cout<<it->index<<" ";
		}
		cout<<endl;
	}
	return 0;
}
