/* PROBLEM
 * The administration of the Tomsk Region firmly believes that it's time to become a megacity (that is, get population of one million).
 * Instead of improving the demographic situation, they decided to achieve its goal by expanding the boundaries of the city.
 * The city of Tomsk can be represented as point on the plane with coordinates (0;0). The city is surrounded with n other locations,
 * the i-th one has coordinates (xi;yi) with the population of ki people. You can widen the city boundaries to a circle of radius r.
 * In such case all locations inside the circle and on its border are included into the city.
 * The goal is to write a program that will determine the minimum radius r, to which is necessary to expand the boundaries of Tomsk, so that it becomes a megacity.
 * Input:
 * The first line of the input contains two integers n and s, the number of locatons around Tomsk city and the population of the city.
 * Then n lines follow. 
 * The i-th line contains three integers, the xi and yi coordinate values of the i-th location and the number ki of people in it.
 * Each coordinate is an integer and doesn't exceed 104 in its absolute value. 
 * It is guaranteed that no two locations are at the same point and no location is at point (0;0).
 * Output:
 * In the output, print "-1" (without the quotes), if Tomsk won't be able to become a megacity. Otherwise, in the first line print
 * a single real number — the minimum radius of the circle that the city needs to expand to in order to become a megacity.
 * The answer is considered correct if the absolute or relative error don't exceed 10^(-6).
 * SOURCE: http://codeforces.com/problemset/problem/424/B?locale=en
 *
 * SOLUTION
 * L'algoritmo memorizza le città ricordandosi solo popolazione e distanza da (0;0).
 * Sorta le città per distanza e poi le aggiunge una alla volta finché non si ottiene una Megacity.
 * COMPLEXITY: O(n*log(n))
 */

#include<bits/stdc++.h>

using namespace std;

#define MEGACITY 1000000

struct city {
	int p;
	double r;
};

struct compare{
	bool operator()(const city& a, const city& b){
		return a.r < b.r;
	}
};

int main(){
	cout<<setprecision(7)<<fixed;
	int n,s;
	cin>>n>>s;
	vector<city> world(n);
	for (int i=0;i<n;i++) {
		int x,y,p;
		cin>>x>>y>>p;
		world[i].p = p;
		world[i].r = sqrt(x*x+y*y);
	}
	sort(world.begin(),world.end(),compare());
	int i=0;
	while(s<MEGACITY && i<n) s+=world[i++].p;
	if (s>=MEGACITY) cout<<world[--i].r<<endl;
	else cout<<-1<<endl;
	return 0;
}
