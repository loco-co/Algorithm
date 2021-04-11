#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int n,k; cin>>n>>k;
	int B[11][11] = {}; //이항계수 배열 
	for(int i=0; i<11; i++) {
		B[i][0] = 1; //n개 중에서 0개 뽑기 
	}
	B[1][1]=1;
	for(int i=2; i<11; i++) {
		for(int j=1; j<11; j++) {
			B[i][j] = B[i-1][j] + B[i-1][j-1];
		} //1개가 추가될때의 값은 1개를 빼둔 나머지들(n-1)중에서 
	} //그 1개를 안 뽑는 경우 + 그 1개를 뽑는 경우 
	cout<<B[n][k];
	return 0;
}
