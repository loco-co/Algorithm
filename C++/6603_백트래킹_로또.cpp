#include <iostream>
using namespace std;
int S[13];
int ans[7]; int k;
void lottery(int);
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	while(1) {
		cin>>k;
		if(k==0) { break; }
		for(int i=0; i<k; i++) {
			cin>>S[i];
		}
		lottery(1);
		cout<<'\n';
	}
	return 0;
}
void lottery(int a) {
	if(a==7) { //종료조건 
		for(int j=1; j<=6; j++) {
			cout<<ans[j]<<' ';
		}
		cout<<'\n';
		return;
	}
	for(int i=0; i<k; i++) {
		if(S[i]>ans[a-1]) { //이전 번호보다 클 때만 탐색 
			ans[a]=S[i];
			lottery(a+1);
		}
	}
}
