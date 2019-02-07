/* In the Main Berland Bank n people stand in a queue at the cashier,
 * everyone knows his/her height hi, and the heights of the other people in the queue.
 * Each of them keeps in mind number ai — how many people who are taller than him/her and stand in queue in front of him.
 * After a while the cashier has a lunch break and the people in the queue seat on the chairs in the waiting room in a random order.
 * When the lunch break was over, it turned out that nobody can remember the exact order of the people in the queue,
 * but everyone remembers his number ai.
 * Your task is to restore the order in which the people stood in the queue if it is possible. 
 * There may be several acceptable orders, but you need to find any of them.
 * Also, you need to print a possible set of numbers hi — the heights of people in the queue, so that the numbers ai are correct.
 * Input:
 * The first input line contains integer n, the number of people in the queue.
 * Then n lines contain descriptions of the people as "namei ai",
 * where namei is a non-empty string consisting of lowercase Latin letters whose length does not exceed 10 characters,
 * ai is an integer that represents the number of people who are higher and stand in the queue in front of person i.
 * It is guaranteed that all names are different.
 * Output:
 * If there's no acceptable order of the people in the queue, print the single line containing "-1" without the quotes.
 * Otherwise, print in n lines the people as "namei hi", where hi is the possible height of a man whose name is namei.
 * Print the people in the order in which they stand in the queue, starting from the head of the queue and moving to its tail.
 * Numbers hi are not necessarily unique.
 * SOURCE: http://codeforces.com/problemset/problem/141/C
 */

#include<bits/stdc++.h>

using namespace std;

struct person {
	string name;
	int davanti;
	int h;
	int posizione;
};
struct compDavanti {
	bool operator()(const person& a, const person& b) {
		return a.davanti < b.davanti;
	}
};
struct compPosizione {
	bool operator()(const person& a, const person& b) {
		return a.posizione < b.posizione;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	person guy[3001];
	for (int i=0;i<n;i++)	{
		cin>>guy[i].name>>guy[i].davanti;
		guy[i].posizione=i;
	}
	
	sort(guy,guy+n,compDavanti());
	
	bool impossible=false;
	int inseriti=0;
	vector<int> ordine;
	for (int i=0;i<n and !impossible;i++) {
		if (guy[i].davanti > inseriti) impossible=true;
		else {
			ordine.insert(ordine.begin()+inseriti-guy[i].davanti , i);
			inseriti++;
		}
		
	}
	if (impossible)	cout<<-1<<endl;
	else {
		for (int i=0;i<n;i++)	guy[ordine[i]].h = i+1;
		for (int i=0;i<n;i++)	cout<<guy[i].name<<" "<<guy[i].h<<endl;
	}
	
	return 0;
}
