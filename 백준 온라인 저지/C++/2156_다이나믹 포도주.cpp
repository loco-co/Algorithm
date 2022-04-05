#include <iostream>
using namespace std;
int max(int, int);
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int n; cin>>n;
	int wine[n];
	for(int i=0; i<n; i++) {
		cin>>wine[i];
	}
	if(n==1) {
		cout<<wine[0];
	}
	else {
		int grape[4][n]; //4가지 상태 경우의수 추적 
		grape[0][0]=wine[0]+wine[1]; //이전꺼도 마시고 이번꺼도 마심 
		grape[1][0]=wine[1]; //이전꺼 패스, 이번꺼 마심 
		grape[2][0]=wine[0]; //이전꺼 마시고 이번꺼 패스 
		grape[3][0]=0; // 둘 다 패스
	
		for(int i=1; i<n-1; i++) {
			grape[0][i]=grape[1][i-1]+wine[i+1]; //이,이전에는 안 마셨어야함 
			grape[1][i]=max(grape[2][i-1]+wine[i+1], grape[3][i-1]+wine[i+1]); //이전꺼 패스한것중 최대값+이번 마신 값 
			grape[2][i]=max(grape[0][i-1], grape[1][i-1]); //이전꺼 마신것중 최대값 
			grape[3][i]=grape[2][i-1]; //이,이전에는 마셨어야함(최적해) 
		}
		int tmp1=max(grape[0][n-2], grape[1][n-2]);
		int tmp2=max(grape[2][n-2], grape[3][n-2]);
		int ans=max(tmp1, tmp2); cout<<ans; //마지막 4가지 상태중 최대값 
		return 0;
	}
}
int max(int a, int b) {
	if(a > b)
		return a;
	else
		return b;
}
