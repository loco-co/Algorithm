#include <iostream>
using namespace std;
int apart[15][15];
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int t; cin>>t;
	for(int i=1; i<15; i++) {
		apart[0][i]=i; //0층 
	}
	for(int i=1; i<15; i++) { //0층부터 14층까지 
		for(int j=1; j<15; j++) { //1호부터 14호까지 구성해감 
			apart[i][j]=apart[i][j-1]+apart[i-1][j];
		} //i층 j호는 자기층 바로 전 집에다가 밑에층 같은호값을 더한 값 
	}
	while(t--) {
		int k,n;
		cin>>k>>n;
		cout<<apart[k][n]<<'\n';
	}
	return 0;
}
