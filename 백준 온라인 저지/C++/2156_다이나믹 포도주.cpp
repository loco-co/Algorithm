#include <iostream>
using namespace std;
int max(int, int);
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int n; cin>>n;
	int wine[n];
	for(int i=0; i<n; i++) {
		cin>>wine[i];
	}
	if(n==1) {
		cout<<wine[0];
	}
	else {
		int grape[4][n]; //4���� ���� ����Ǽ� ���� 
		grape[0][0]=wine[0]+wine[1]; //�������� ���ð� �̹����� ���� 
		grape[1][0]=wine[1]; //������ �н�, �̹��� ���� 
		grape[2][0]=wine[0]; //������ ���ð� �̹��� �н� 
		grape[3][0]=0; // �� �� �н�
	
		for(int i=1; i<n-1; i++) {
			grape[0][i]=grape[1][i-1]+wine[i+1]; //��,�������� �� ���̾���� 
			grape[1][i]=max(grape[2][i-1]+wine[i+1], grape[3][i-1]+wine[i+1]); //������ �н��Ѱ��� �ִ밪+�̹� ���� �� 
			grape[2][i]=max(grape[0][i-1], grape[1][i-1]); //������ ���Ű��� �ִ밪 
			grape[3][i]=grape[2][i-1]; //��,�������� ���̾����(������) 
		}
		int tmp1=max(grape[0][n-2], grape[1][n-2]);
		int tmp2=max(grape[2][n-2], grape[3][n-2]);
		int ans=max(tmp1, tmp2); cout<<ans; //������ 4���� ������ �ִ밪 
		return 0;
	}
}
int max(int a, int b) {
	if(a > b)
		return a;
	else
		return b;
}
