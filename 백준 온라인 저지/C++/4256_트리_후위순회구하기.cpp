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
			in[k]=j; //원소 내용을 인덱스로 받기 
		} //나중에 서치 시간을 줄여줌 
		getpost(1,n,1);
		cout<<'\n';
	}
	return 0;
}
void getpost(int low, int high, int index) {
	if(low>high) { return; }
	int root=pre[index]; //전위의 첫번째는 항상 루트 
	int m=in[root]; //분기점 m은 in의 인덱스를 구하자. 
	getpost(low, m-1, index+1); //분기해서 재귀로 순회 
	getpost(m+1, high, index+1+m-low); //마지막 항은 알아서 자연스레 구해짐,, 
	cout<<root<<' '; //후위 
}
//low+1, m, m+1, high
