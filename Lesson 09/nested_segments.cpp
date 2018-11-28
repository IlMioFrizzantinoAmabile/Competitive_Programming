/* You are given n segments on a line. There are no ends of some segments that coincide.
 * For each segment find the number of segments it contains.
 * Input:
 * The first line contains a single integer n, the number of segments on a line.
 * Each of the next n lines contains two integers li and ri, the coordinates of the left and the right ends of the i-th segment.
 * It is guaranteed that there are no ends of some segments that coincide.
 * Output:
 * Print n lines. The j-th of them should contain the only integer aj — the number of segments contained in the j-th segment.
 * SOURCE: http://codeforces.com/problemset/problem/652/D?locale=en
 */

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200001;
int BIT[N+1];

int sum(int pos) {
	int tot=0;
	pos++;
	while (pos!=0) {
		tot+=BIT[pos];
		pos -= pos & -pos;
	}
	return tot;
}

void update(int pos, int val) {
	pos++;
	while (pos<N) {
		BIT[pos]+=val;
		pos += pos & -pos;
	}
}

struct segment{
	int start, end, endIn;
	int index;
	int result;
};
struct compStart{
	bool operator()(const segment& a, const segment& b){
		return a.start > b.start;
	}
};
struct compEnd{
	bool operator()(const segment& a, const segment& b){
		return a.end < b.end;
	}
};
struct compIndex{
	bool operator()(const segment& a, const segment& b){
		return a.index < b.index;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<segment> seg(n);
	for (int i=0;i<n;i++) {
		cin>>seg[i].start>>seg[i].end;
		seg[i].index=i;
	}
	sort(seg.begin(),seg.end(), compEnd());
	for (int i=0;i<n;i++)	seg[i].endIn = i+1;
	sort(seg.begin(),seg.end(), compStart());
	for (int i=0;i<n;i++) {
		seg[i].result = sum(seg[i].endIn);
		update(seg[i].endIn, 1);
	}
	sort(seg.begin(),seg.end(), compIndex());
	for (int i=0;i<n;i++)	cout<<seg[i].result<<endl;
	return 0;
}
