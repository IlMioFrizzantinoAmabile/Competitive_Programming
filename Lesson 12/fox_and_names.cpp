/* PROBLEM
 * Fox Ciel is going to publish a paper on FOCS (Foxes Operated Computer Systems, pronounce: "Fox").
 * She heard a rumor: the authors list on the paper is always sorted in the lexicographical order.
 * After checking some examples, she found out that sometimes it wasn't true.
 * On some papers authors' names weren't sorted in lexicographical order in normal sense.
 * But it was always true that after some modification of the order of letters in alphabet, the order of authors becomes lexicographical!
 * She wants to know, if there exists an order of letters in Latin alphabet such that the names on the paper she is submitting are
 * following in the lexicographical order. If so, you should find out any such order.
 * Lexicographical order is defined in following way. When we compare s and t, first we find the leftmost position with differing 
 * characters: si ≠ ti. If there is no such position (i. e. s is a prefix of t or vice versa) the shortest string is less.
 * Otherwise, we compare characters si and ti according to their order in alphabet.
 * Input:
 * The first line contains an integer n: number of names.
 * Each of the following n lines contain one string namei, the i-th name. Each name contains only lowercase Latin letters.
 * All names are different.
 * Output:
 * If there exists such order of letters that the given names are sorted lexicographically, output any such order as a permutation 
 * of characters 'a'–'z' (i. e. first output the first letter of the modified alphabet, then the second, and so on).
 * Otherwise output a single word "Impossible" (without quotes).
 * SOURCE: http://codeforces.com/problemset/problem/510/C?locale=en
 *
 * SOLUTION
 * L'algoritmo da ogni coppia di parole consecutive deduce un ordinamento tra lettere, le prime diverse.
 * Così facendo si trasforma facilmente il problema originario in un problema su un grafo, in cui i nodi sono le lettere e gli
 * archi sono gli ordinamenti. Il problema diventa chiedersi se questo grafo è un DAG.
 * Un possibile ordine dell'alfabeto, se esiste, sarà quindi dato da un qualsiasi possibile ordinamento dei nodi nel DAG.
 * Assumiamo che la cardinalità dell'alfabeto sia costante (=26 nel nostro caso).
 * COMPLEXITY: O(n)
 */

#include<bits/stdc++.h>

using namespace std;

bool order[26][26];
int color[26];
bool impossible;
stack<int> s;

void DFS(int node) {
	color[node]=1;
	for (int i=0;i<26;i++) if (order[i][node]) if (node!=i) {
		if(color[i]==1) impossible=true;
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
