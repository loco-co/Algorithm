#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int n,k; cin>>n>>k;
	int count=0;
	int arr[n+1];
	for(int i=2; i<=n; i++) {
		arr[i]=i;
	}
	for(int i=2; i<=n; i++) {
		if(arr[i]==i) { //���� �������� ���� �Ҽ��� ���� 
			for(int t=i; t<=n; t += i) { //t�� �����ŭ �ݺ� 
				if(arr[t]==t) { //t�� ����� ���� �ɷ����� �ʾ����� 
					arr[t]=0; //�Ÿ��� 
					count++; //Ƚ�� ���� 
					if(count==k) {
						cout<<t; return 0;
					}
				}
			}
		}
	}
}
