#include <iostream>
using namespace std;
int pre[1001];
int in[1001];
void getpost(int low, int high, int index);
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--) {
		int n,k; cin>>n;
		for(int i=1; i<=n; i++)
			cin>>pre[i];
		for(int j=1; j<=n; j++) {
			cin>>k;
			in[k]=j; //���� ������ �ε����� �ޱ� 
		} //���߿� ��ġ �ð��� �ٿ��� 
		getpost(1,n,1);
		cout<<'\n';
	}
	return 0;
}
void getpost(int low, int high, int index) {
	if(low>high) { return; }
	int root=pre[index]; //������ ù��°�� �׻� ��Ʈ 
	int m=in[root]; //�б��� m�� in�� �ε����� ������. 
	getpost(low, m-1, index+1); //�б��ؼ� ��ͷ� ��ȸ 
	getpost(m+1, high, index+1+m-low); //������ ���� �˾Ƽ� �ڿ����� ������,, 
	cout<<root<<' '; //���� 
}
//low+1, m, m+1, high
