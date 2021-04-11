#include <iostream>
using namespace std;
int bridge[30][30];
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	for(int i=1; i<30; i++) {
		bridge[1][i]=i; //다리 1개일때 값 초기화 
	}
	for(int i=2; i<30; i++) { //규칙에 따라 배열을 채워나감 
		for(int j=i; j<30; j++) { //맨 밑 동쪽 사이트 1개가 늘어난 값은 
			bridge[i][j]=bridge[i][j-1]+bridge[i-1][j-1];
		} //그 동쪽사이트 1개를 안쓸때 + 그 동쪽 사이트 1개를 쓸때 
	}
	
	int t; cin>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		cout<<bridge[n][m]<<'\n';
	}
	return 0;
}
