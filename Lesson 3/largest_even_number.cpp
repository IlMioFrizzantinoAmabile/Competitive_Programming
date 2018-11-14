#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int T;
	cin>>T;
	char c=getchar();
	for (int i=0;i<T;i++){
		vector<int> digits(10,0);
		while ((c=getchar())>='0' && c<='9')	digits[c-'0']++;
		int evenDig = -1;
		for (int j=0; j<10 && evenDig<0; j=j+2)	if (digits[j]>0) {
			evenDig=j;
			digits[j]--;		
		}
		for (int j=9; j>=0; j--) while (digits[j]) {
				cout<<j;
				digits[j]--;
		}
		if (evenDig>=0)	cout<<evenDig;
		cout<<endl;
	}
	return 0;
}