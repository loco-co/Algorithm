#include <iostream>
#define max 123456*2
using namespace std;
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	while(1) {
		int n; cin>>n;
		if(n==0) { break; }
		bool prime[max+1];
		for(int i=0; i<=max; i++) {
			prime[i]=true;
		}
		
		for(int i=2; i<=max/2; i++) { //�����佺�׳׽��� ü�� ������� 
			int k = i*2; //�ִ�������� �Ҽ��� ���ϴ� ���� 
			while(k<=max) {
				prime[k]=false;
				k += i;
			}
		}
		
		int count=0;
		for(int i=n+1; i<=2*n; i++) { //������ �°� 
			if(prime[i]) { count++; } //�Ҽ��� üũ�� ���� �����ִ� ���� 
		}
		cout<<count<<'\n';
	}
	return 0;
}
