#include <iostream>
using namespace std;
int max(int, int, int);
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int n; cin>>n;
	int wine[n];
	for(int i=0; i<n; i++) {
		cin>>wine[i];
	}
	int dp[n]; //n��°���� ���� ���� ���� �� 
	dp[0]=wine[0];
	dp[1]=wine[0]+wine[1];
	dp[2]=max(dp[1], wine[1]+wine[2], wine[0]+wine[2]);
	for(int i=3; i<n; i++) {
		dp[i]=max(dp[i-1], wine[i]+dp[i-2], wine[i]+wine[i-1]+dp[i-3]);
	} //�ȸ԰ų�, �Դµ� �� ���� �����ų�, ���� �ΰ����� �԰ų�. 
	cout<<dp[n-1];
	return 0;
}
int max(int a, int b, int c) {
	if (a > b) {
		if (a > c)
			return a;
		else
			return c;	
	}
	else {
		if (b > c)
			return b;
		else
			return c;
	}
}
