#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int t; cin>>t;
	int H,W,N,roomno,x,y;
	for(int i=0; i<t; i++) {
		cin>>H>>W>>N;
		if(N%H==0) { //N�� ������ ������ �������� 
			x=N/H; // �� ��
			y=H; //���� �״�� ���� 
		} //��, �� ���� ������ �� 
		else {
			x=N/H+1; // �� ���� �� 
			y=N%H; //������ ������ 
		}
		roomno=y*100+x;
		cout<<roomno<<'\n';
	}
	return 0;
}
