#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int d,k; cin>>d>>k;
	int X[31]; int Y[31];
	X[1]=1; X[2]=0;
	Y[1]=0; Y[2]=1;
	for(int i=3; i<31; i++) {
		X[i] = X[i-2] + X[i-1];
		Y[i] = Y[i-2] + Y[i-1];
	} //d�Ͽ� �ʿ��� a,b�� ��� ��� 
	int ca=X[d]; int cb=Y[d];
	int a=1; int b;
	while(true) { //�� k���� ������ �������� �����ϴ� a�� bã�� 
		int q = k-a*ca; //a�� 1���� ���Ʈ�����ϰ� ã�´� 
		if(q % cb==0) { //b�ε� ������ �������� 
			b = q/cb; //�� b�� ���� 
			break;
		}
		a++;
	}
	cout<<a<<'\n'<<b;
	return 0;
}
