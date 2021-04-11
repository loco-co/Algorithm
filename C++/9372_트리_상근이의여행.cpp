#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--) {
		int n,m,a,b; cin>>n>>m;
		for(int i=0; i<m; i++) {
			cin>>a>>b;
		} //정답은 트리의 엣지 갯수 
		cout<<n-1<<'\n';
	}
	return 0;
}
