#include <iostream>
using namespace std;
int e,s,m,year;
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int E,S,M; cin>>E>>S>>M;
	while(1) { //브루트포스 
		if(e==E && s==S && m==M) {
			cout<<year;
			return 0;
		}
		year++; e++; s++; m++;
		if(e>15) { e=1; } //자릿수 넘어가면 다시 1로 
		if(s>28) { s=1; }
		if(m>19) { m=1; }
	}
}
