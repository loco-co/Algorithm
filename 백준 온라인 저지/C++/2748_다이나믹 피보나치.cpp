#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int n; cin>>n;
	long long F[n+1]={0,1};
	for(int i=2; i<=n; i++) {
		F[i]=F[i-2]+F[i-1];
	}
	cout<<F[n];
	return 0;
}
