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