#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int n,m; cin>>n>>m;
	int array[n+1]; int sum[n+1]; sum[0]=0;
	for(int i=1; i<=n; i++) {
		cin>>array[i]; //�Է��� �����鼭 
		sum[i]=sum[i-1]+array[i]; //������ ���� ���� ���ؼ� �����س��� 
	}
	while(m--) {
		int left, right;
		cin>>left>>right;
		cout<<sum[right]-sum[left-1]<<'\n';
	}
	return 0;
}
