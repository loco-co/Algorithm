#include <iostream>
using namespace std;
int bridge[30][30];
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	for(int i=1; i<30; i++) {
		bridge[1][i]=i; //�ٸ� 1���϶� �� �ʱ�ȭ 
	}
	for(int i=2; i<30; i++) { //��Ģ�� ���� �迭�� ä������ 
		for(int j=i; j<30; j++) { //�� �� ���� ����Ʈ 1���� �þ ���� 
			bridge[i][j]=bridge[i][j-1]+bridge[i-1][j-1];
		} //�� ���ʻ���Ʈ 1���� �Ⱦ��� + �� ���� ����Ʈ 1���� ���� 
	}
	
	int t; cin>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		cout<<bridge[n][m]<<'\n';
	}
	return 0;
}
