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
		} //������ Ʈ���� ���� ���� 
		cout<<n-1<<'\n';
	}
	return 0;
}
