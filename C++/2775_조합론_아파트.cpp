#include <iostream>
using namespace std;
int apart[15][15];
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int t; cin>>t;
	for(int i=1; i<15; i++) {
		apart[0][i]=i; //0�� 
	}
	for(int i=1; i<15; i++) { //0������ 14������ 
		for(int j=1; j<15; j++) { //1ȣ���� 14ȣ���� �����ذ� 
			apart[i][j]=apart[i][j-1]+apart[i-1][j];
		} //i�� jȣ�� �ڱ��� �ٷ� �� �����ٰ� �ؿ��� ����ȣ���� ���� �� 
	}
	while(t--) {
		int k,n;
		cin>>k>>n;
		cout<<apart[k][n]<<'\n';
	}
	return 0;
}
