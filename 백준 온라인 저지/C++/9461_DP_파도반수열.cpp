#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int t; cin>>t;
	long long P[101]; //�Ǻ���ġ�� ���ȣ���� �ſ�ũ�� 
		P[1]=1; P[2]=1; P[3]=1; //�ĵ��� ���� 
		for(int i=4; i<101; i++) {
			P[i]=P[i-3]+P[i-2];
		}
	while(t--) {
		int n; cin>>n;
		cout<<P[n]<<'\n';
	}
	return 0;
}
