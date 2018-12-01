/* The "BerCorp" company has got n employees. These employees can use m approved official languages for the formal correspondence.
 * The languages are numbered with integers from 1 to m. For each employee we have the list of languages, which he knows.
 * This list could be empty, i. e. an employee may know no official languages. But the employees are willing to learn any number
 * of official languages, as long as the company pays their lessons. A study course in one language for one employee costs 1 berdollar.
 * Find the minimum sum of money the company needs to spend so as any employee could correspond to any other one
 * (their correspondence can be indirect, i. e. other employees can help out translating).
 * Input:
 * The first line contains two integers n and m, the number of employees and the number of languages.
 * Then n lines follow — each employee's language list. 
 * At the beginning of the i-th line is integer ki (0 ≤ ki ≤ m) — the number of languages the i-th employee knows.
 * Next, the i-th line contains ki integers — aij (1 ≤ aij ≤ m) — the identifiers of languages the i-th employee knows.
 * It is guaranteed that all the identifiers in one list are distinct. Note that an employee may know zero languages.
 * The numbers in the lines are separated by single spaces.
 * Output:
 * Print a single integer — the minimum amount of money to pay so that in the end every employee could write a letter to every
 * other one (other employees can help out translating).
 * SOURCE: http://codeforces.com/problemset/problem/277/A?locale=en
 */

#include<bits/stdc++.h>

using namespace std;

vector< vector<int> > edge;
vector<bool> seen;

void DFS(int node) {
	seen[node]=true;
	vector<int>::iterator it;
	for (it=edge[node].begin(); it!=edge[node].end(); it++)
		if (!seen[*it]) DFS(*it);
}

int CountConnectedComponents (int dim) {
	int n=0;
	for (int i=0;i<dim;i++) if(!seen[i]) {
		DFS(i);
		n++;
	}
	return n;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	edge.reserve(n);
	seen.reserve(n);
	seen.assign(n,false);
	vector< vector<int> > speak(m);
	bool atLeastOneLan = false;
	for (int employee=0;employee<n;employee++) {
		int numOfLan;
		cin>>numOfLan;
		atLeastOneLan = atLeastOneLan or (numOfLan>0);
		while (numOfLan--) {
			int language;
			cin>>language;
			language--;
			vector<int>::iterator it;
			for (it=speak[language].begin(); it!=speak[language].end(); it++) {
				edge[*it].push_back(employee);
				edge[employee].push_back(*it);
			}
			speak[language].push_back(employee);
		}
	}
	if (atLeastOneLan)	cout<<CountConnectedComponents(n)-1<<endl;
	else cout<<n<<endl;
	
	return 0;
}
