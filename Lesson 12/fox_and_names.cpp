#include<bits/stdc++.h>

using namespace std;

bool order[26][26];
int color[26];
bool impossible;
stack<int> s;

void DFS(int node) {
	color[node]=1;
	for (int i=0;i<26;i++) if (order[i][node]) if (node!=i) {
		if(color[i]==1) {
			impossible=true;
		}
		else if(color[i]==0) DFS(i);
	}
	color[node]=2;
	s.push(node);
}

vector<int> DAG() {
	vector<int> result(26);
	for (int i=0;i<26;i++) if(color[i]==0) DFS(i);
	int i=26;
	while (!s.empty()) {
		result[--i]=s.top();
		s.pop();
	}
	return result;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<string> name(n);		
	for (int i=0;i<n;i++) cin>>name[i];
	for (int i=1;i<n;i++) {
		string A = name[i-1];
		string B = name[i];
		int len = min(A.length(),B.length());
		int j=0;
		while (j<len and A[j]==B[j]) j++;	
		if (j<len) order[A[j]-'a'][B[j]-'a'] = true;
		else if (A.length()>B.length()) impossible=true;
	}
	vector<int> ord = DAG();if (impossible) cout<<"Impossible"<<endl;
	else for (int i=0;i<26;i++) cout<<(char)(ord[i]+'a');
	return 0;
}