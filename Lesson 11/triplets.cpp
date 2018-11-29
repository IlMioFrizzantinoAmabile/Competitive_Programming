/* Course Exam, 14/02/2018
 * SOURCE: https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/Exams/Text14022018.pdf
 */

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct fenwick_tree {
	vector<int> BIT;
	fenwick_tree (int n) : BIT(n+2,0) {}
	int sum(int pos) {
		int tot=0;
		pos++;
		while (pos>0) {
			tot+=BIT[pos];
			pos -= pos & -pos;
		}
		return tot;
	}
	void update(int pos, int val) {
		pos++;
		while (pos<BIT.size()) {
			BIT[pos]+=val;
			pos += pos & -pos;
		}
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<int> A(n);
	for (int i=0;i<n;i++) {
		int x;
		cin>>x;
		A[i]=x+1;
	}
	fenwick_tree BITlow(n);
	vector<int> lower(n);
	for (int i=0;i<n;i++) {
		lower[i] = BITlow.sum(A[i]-1);
		BITlow.update(A[i],1);
	}
	fenwick_tree BIThigh(n);
	vector<int> higher(n);
	for (int i=n-1;i>=0;i--) {
		higher[i] = BIThigh.sum(n-A[i]);
		BIThigh.update(n+1-A[i],1);
	}
	int answer=0;
	for (int i=0;i<n;i++)	answer+=lower[i]*higher[i];
	cout<<answer;
	return 0;
}
