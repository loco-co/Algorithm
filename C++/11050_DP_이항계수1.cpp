#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int n,k; cin>>n>>k;
	int B[11][11] = {}; //���װ�� �迭 
	for(int i=0; i<11; i++) {
		B[i][0] = 1; //n�� �߿��� 0�� �̱� 
	}
	B[1][1]=1;
	for(int i=2; i<11; i++) {
		for(int j=1; j<11; j++) {
			B[i][j] = B[i-1][j] + B[i-1][j-1];
		} //1���� �߰��ɶ��� ���� 1���� ���� ��������(n-1)�߿��� 
	} //�� 1���� �� �̴� ��� + �� 1���� �̴� ��� 
	cout<<B[n][k];
	return 0;
}
