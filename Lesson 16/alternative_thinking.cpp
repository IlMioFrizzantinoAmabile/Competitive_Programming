#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d\n",&n);
	int tot=3;
	char last,now;
	last=getchar();
	for (int i=1;i<n;i++) {
		now=getchar();
		if (now!=last) tot++;
		last=now;
	}
	printf("%d\n",min(tot,n));
	return 0;
}