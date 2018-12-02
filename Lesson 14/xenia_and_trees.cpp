#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAX 100000
#define INFINITE 1000000000

map<int,int> dist[MAX];
int answer[MAX];

struct centroid_decomposition {
	set<int> *sons;
	int* dad;
	int* peso;
	int n;
	centroid_decomposition (set<int>* graph, int dim, int* d, int* p) : sons(graph), n(dim), dad(d), peso(p) {
		build(0,-1);
	}
	void build(int nodo, int padre) {
		//build viene lanciata al più O(log(n)) volte, con un costo totale di O(n*log(n)^2)
		int n = dfs(nodo,padre);				//O(numero "nipoti" del nodo)
		int centroid = dfsCent(nodo,padre,n);	//O(numero "nipoti" del nodo)
		dfsDist(centroid,padre,centroid,0);		//O(log(n)*numero "nipoti" del nodo)
		dad[centroid] = padre;	
		set<int>::iterator son;
		for (son=sons[centroid].begin(); son!=sons[centroid].end(); son++) {
			sons[*son].erase(centroid); //in tot ci sono al più n-1 erase, ognuna costa O(log(n))
			build(*son,centroid);
			//rilacio "build" su sottografi disgiunti di dimensione < n/2
		}
	}
	int dfs(int nodo, int padre) {
		peso[nodo]=1;
		set<int>::iterator son;
		for (son=sons[nodo].begin(); son!=sons[nodo].end(); son++) 
			if (*son!=padre) peso[nodo]+=dfs(*son,nodo);
		return peso[nodo];
	}
	int dfsCent(int nodo, int padre, int n) {
		set<int>::iterator son;
		for (son=sons[nodo].begin(); son!=sons[nodo].end(); son++) 
			if (*son!=padre and peso[*son]>n/2) return dfsCent(*son,nodo,n);
		return nodo;
	}
	void dfsDist(int nodo, int padre, int ancestor, int h) {
		dist[ancestor].insert(make_pair(nodo,h));
		set<int>::iterator son;
		for (son=sons[nodo].begin(); son!=sons[nodo].end(); son++)
			if (*son!=padre) dfsDist(*son,nodo,ancestor,h+1);
	}
	int operator[](int i) {
		return dad[i];
	}
};

void update(int node, centroid_decomposition CD) {
	//update risale l'albero dei centroidi, e ogni passo va in O(log(n)) per la dist
	//quindi al più impiega O(log(n)^2)
	int tmp=node;
	while (tmp>=0) {
		answer[tmp] = min(answer[tmp] , dist[tmp][node]);
		tmp = CD[tmp];
	}
}

int query(int node, centroid_decomposition CD) {
	//query risale l'albero dei centroidi, e ogni passo va in O(log(n)) per la dist
	//quindi al più impiega O(log(n)^2)
	int ans=answer[node];
	int tmp=node;
	while (tmp>=0 and ans) {
		ans = min(answer[tmp]+dist[tmp][node] , ans);
		tmp = CD[tmp];
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	set<int> sons[MAX];
	int CD1[MAX];	//alloco staticamente gli array che
	int CD2[MAX];	//utilizzerà la centroid decomposition
	for (int i=1;i<n;i++) {						//costruisco l'albero in O(n)
		int a,b;
		cin>>a>>b;
		a--;b--;
		sons[a].insert(b);
		sons[b].insert(a);
	}
	centroid_decomposition CD(sons,n,CD1,CD2);	//decomposizione in O(n*log(n)^2)
	for (int i=0;i<n;i++) answer[i]=INFINITE;
	update(0,CD);
	while (m--) {								//operazioni in O(m*log(n)^2)
		int q,node;
		cin>>q>>node;
		node--;
		if (q==1) update(node,CD);
		else if (q==2) cout<<query(node,CD)<<endl;
	}
	return 0;
}