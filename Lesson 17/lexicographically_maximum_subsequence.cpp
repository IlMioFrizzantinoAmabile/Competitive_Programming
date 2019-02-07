#include<bits/stdc++.h>

using namespace std;

void append(string& max, char &c) {
	int length=max.length();
	max.resize(length+1);
	max[length]=c;
}

int main(){
	string s,max;
	cin>>s;
	int length=s.length();
	int occ[26];
	for (int c=0;c<26;c++) occ[c]=0;
	for (int i=0;i<length;i++) occ[s[i]-'a']++;
	for (int i=0;i<length;i++) {
		int c=25;
		while (c>s[i]-'a' and occ[c]==0) c--;
		if (c==s[i]-'a')	append(max,s[i]);
		occ[s[i]-'a']--;
	}
	cout<<max<<endl;
	return 0;
}