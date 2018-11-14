#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> array,lleft,rright;

ll merge (int start, int end) {
	if (end-start > 1) {
		int length1 = (end-start)/2;
		int length2 = end - start - length1;
		ll pt1 = merge (start, start + length1);
		ll pt2 = merge (start + length1, end);
		for (int i = 0; i < length1; i++)	lleft[i] = array[start+i];
		for (int j = 0; j < length2; j++)	rright[j] = array[start+length1+j];
		int k=start, i=0, j=0, moltiplicatore=0;
		ll scambi=0;
		while (i < length1 && j < length2) {
			if (lleft[i] <= rright[j]) {
				array[k] = lleft[i];
				i++;
				scambi+=moltiplicatore;
			}
			else {
				array[k] = rright[j];
				j++;
				moltiplicatore++;
			}
			k++;
		}
		while (i < length1) {
			array[k] = lleft[i];
			i++;
			k++;
			scambi+=moltiplicatore;
		}
		while (j < length2) {
			array[k] = rright[j];
			j++;
			k++;
		}
		return scambi+pt1+pt2;
	}
	else return 0;
}

int main(){
	int T;
	cin>>T;
	for (int i=0;i<T;i++){
		int N;
		cin>>N;
		array.reserve(N);
		lleft.reserve(N);
		rright.reserve(N);
		for (int j=0;j<N;j++) {
			cin>>array[j];
		}
		cout<<merge(0,N)<<endl;
	}
	return 0;
}