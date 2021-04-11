#include <iostream>
using namespace std;
int Max(int, int);
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int n; cin>>n;
	int stair[n];
	for(int i=0; i<n; i++) {
		cin>>stair[i];
	}
	int dp[n]; //n번째 계단까지 밟은 최대점수 
	dp[0]=stair[0];
	dp[1]=stair[0]+stair[1];
	dp[2]=Max(stair[0]+stair[2], stair[1]+stair[2]);
	for(int i=3; i<n; i++) {
		dp[i]=Max(dp[i-2]+stair[i], dp[i-3]+stair[i-1]+stair[i]);
	} //전에 뛰고 밟는 경우, 전,전에 뛰고 두개연속 밟는 경우, 안 밟는 경우(x)
	cout<<dp[n-1];
	return 0;
}
int Max(int a, int b) {
	if(a > b)
		return a;
	else
		return b;
}
