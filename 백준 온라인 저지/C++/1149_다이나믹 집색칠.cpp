#include <iostream>
using namespace std;
int min(int, int);
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int n; cin>>n;
	int color[n][3];
	for(int i=0; i<n; i++) {
		for(int j=0; j<3; j++) {
			cin>>color[i][j];
		}
	}
	for(int i=n-1; i>0; i--) { 
		for(int j=0; j<3; j++) { //�Ʒ������� ���� 
			if(j==0) {
				color[i-1][j]=min(color[i][1]+color[i-1][j],
				color[i][2]+color[i-1][j]); //���� ���� ���� �ٸ� �ΰ��� ���� ������ 
			}
			else if(j==1) {
				color[i-1][j]=min(color[i][0]+color[i-1][j],
				color[i][2]+color[i-1][j]);
			}
			else {
				color[i-1][j]=min(color[i][0]+color[i-1][j],
				color[i][1]+color[i-1][j]);
			}
		}
	}
	int ans=min(color[0][0], color[0][1]); //3�� �߿� ���� ���� ��
	ans=min(ans, color[0][2]);
	cout<<ans;
	return 0;
}
int min(int a, int b) {
	if(a < b)
		return a;
	else
		return b;
}
