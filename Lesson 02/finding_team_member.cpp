/* PROBLEM
 * There is a programing contest named SnakeUp, 2n people want to compete for it.
 * In order to attend this contest, people need to form teams of exactly two people.
 * You are given the strength of each possible combination of two people. All the values of the strengths are distinct.
 * Every contestant hopes that he can find a teammate so that their team’s strength is as high as possible.
 * That is, a contestant will form a team with highest strength possible by choosing a teammate from ones who are willing to be a teammate with him/her.
 * More formally, two people A and B may form a team if each of them is the best possible teammate (among the contestants that remain unpaired) for the other one.
 * The task is to determine who will be each person’s teammate?
 * Input:
 * There are 2n lines in the input.
 * The first line contains an integer n (1 ≤ n ≤ 400) — the number of teams to be formed.
 * The i-th line (i > 1) contains i - 1 numbers ai1, ai2, ... , ai(i - 1).
 * Here aij denotes the strength of a team consisting of person i and person j (people are numbered starting from 1).
 * Output:
 * Print a line containing 2n numbers. The i-th number should represent the number of teammate of i-th person.
 * SOURCE: http://codeforces.com/problemset/problem/579/B?locale=en
 *
 * SOLUTION
 * L'algoritmo sorta le coppie in ordine di strenght decrescente, dopodiché scorre dall'inizio e assegna le coppie non ancora assegnate.
 * COMPLEXITY: O(n^2*log(n))
 */ 

#include<bits/stdc++.h>

using namespace std;

struct pairr{
	int strenght;
	int first;
	int second;
};
struct compare{
	bool operator()(const pairr& a, const pairr& b){
		return a.strenght > b.strenght;
	}
};

int main(){
	int N;
	cin>>N;
	vector<pairr> v(2*N*(N-1));
	for (int i=1;i<2*N;i++) for(int j=0;j<i;j++) {
		int s;
		cin>>s;
		pairr nuovo = {s,j,i};
		v.push_back(nuovo);
	}
	sort(v.begin(),v.end(),compare());
	vector<int> team(2*N, -1);
	for (vector<pairr>::iterator it=v.begin(); it!=v.end(); it++) {
		if (team[it->first]<0 && team[it->second]<0) {
			team[it->first] = it->second;
			team[it->second] = it->first;
		}
	}
	for (vector<int>::iterator it=team.begin(); it!=team.end(); it++) {
		cout<<*it+1<<" ";
	}
	cout<<endl;
	return 0;
}
