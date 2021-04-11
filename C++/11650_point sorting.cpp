#include <iostream>
#include <algorithm>
using namespace std;
struct point {
	int x,y;
};
bool cmp(point a, point b) {
	if(a.x == b.x)
		return a.y < b.y;
	else
		return a.x < b.x;
}
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int N; cin>>N;
	point P[N];
	for(int i=0; i<N; i++) {
		cin>>P[i].x>>P[i].y;
	}
	sort(P, P+N, cmp);
	for(int i=0; i<N; i++) {
		cout<<P[i].x<<' '<<P[i].y<<'\n';
	}
	return 0;
}
