#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int t,n; cin>>t;
	while(t--) {
		cin>>n;
		int s[n]; int m[n]; bool survive[n];
		int surv=n; //��ü �ο� ���� 
		for(int i=0; i<n; i++) {
			cin>>s[i]>>m[i];
			survive[i]=true;
		}
		for(int i=0; i<n; i++) {
			if(survive[i]) { //��Ƴ��� ����� �������� 
				for(int j=0; j<n; j++) {
					if(survive[j] && s[j]>s[i] && m[j]>m[i]) { //��Ƴ��Ҵµ� s�� m����� ���غ��� ��� ū ����� 
						survive[j]=false; //�����ϰ� 
						surv--; //�ο� ���� 
					}
				}
			}
		}
		cout<<surv<<'\n';
	}
	return 0;
}
