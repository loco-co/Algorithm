#include <iostream>
using namespace std;
int Max(int, int);
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int n; cin>>n;
	int tri[n][n];
	for(int i=0; i<n; i++) {
		for(int j=0; j<=i; j++) {
			cin>>tri[i][j];
		}
	}
	for(int i=n-1; i>0; i--) {
		for(int j=i; j>=1; j--) {
			tri[i-1][j-1]=Max(tri[i][j]+tri[i-1][j-1], tri[i][j-1]+tri[i-1][j-1]);
		}
	}
	cout<<tri[0][0];
}
int Max(int a, int b) {
	if (a>b)
		return a;
	else
		return b;
}
