#include <iostream>
using namespace std;
int l,c;
char arr[16];
char ans[16];
void travel(int, int, int);
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	cin>>l>>c;
	for(int i=0; i<c; i++) {
		cin>>arr[i];
	}
	for(int i=0; i<c; i++) { //�����ϰ� ���� 
		for(int j=0; j<c-1; j++) {
			if(arr[j]>arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
		}
	}
	travel(1,0,0);
	return 0;
}
void travel(int n, int mo, int ja) {
	if(n==l+1) { //�������� 
		if(mo>=1 && ja>=2) { //��� Ž���� ���ǿ� �������� ��� 
			for(int i=1; i<=l; i++) { //��� Ž������ ������ ������ �������� 
				cout<<ans[i];
			}
			cout<<'\n';
		}
		return;
	}
	for(int i=0; i<c; i++) {
		if(arr[i]>ans[n-1]) { //�����ϸ�, ���� ���� ���ں��� �ĺ� ���ڵ� �� ū ���ڵ鸸 Ž�� 
			ans[n]=arr[i];
			if(ans[n]=='a' || ans[n]=='e' || ans[n]=='i' || ans[n]=='o' || ans[n]=='u') {
				mo++; //���� ���� ���� 
			}
			else { ja++; }
			
			travel(n+1, mo, ja);
			
			if(ans[n]=='a' || ans[n]=='e' || ans[n]=='i' || ans[n]=='o' || ans[n]=='u') {
				mo--; //Ż�� �� ���� ���� ������� 
			}
			else { ja--; }
		}
	}
}
