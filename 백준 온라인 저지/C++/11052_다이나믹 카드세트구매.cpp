#include <iostream>
using namespace std;
int max(int, int);
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int n; cin>>n;
	int P[n+1]; //카드세트가격 
	for(int i=1; i<=n; i++) {
		cin>>P[i];
	}
	int dp[n+1]={}; //dp[n]은 n장의 카드를 살 수 있는 최대값 
	dp[1]=P[1]; dp[0]=0;
	for(int i=2; i<=n; i++) {
		for(int j=1; j<=i; j++) { //마지막에 1,2,...,n장을 살 때 비교 
			dp[i]=max(dp[i], dp[i-j]+P[j]);
		}
	}
	cout<<dp[n];
	return 0; 
}
int max(int a, int b) {
	if(a > b)
		return a;
	else
		return b;
}
