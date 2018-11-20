#include<bits/stdc++.h>

using namespace std;

vector<int> vec;

int check_BST(int root, int end) {
	if (end-root<2) return 1;
	int left_branch = 1;
	int last=end;
	for (int i=root+1; i<=end; i++) {
		if (vec[i]>vec[root]) {
			if (left_branch) {
				left_branch=0;
				last=i;
			}
		}
		else if (!left_branch) return 0;
	}
	return check_BST(root+1,last) * check_BST(last+1,end);
}

int main(){
	int T;
	cin>>T;
	for (int i=0;i<T;i++){
		int N;
		cin>>N;
		vec.reserve(N);
		for (int i=0;i<N;i++) cin>>vec[i];
		cout<<check_BST(0,N-1)<<endl;
	}
	return 0;
}