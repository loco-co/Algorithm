#include <iostream>
using namespace std;
void backtrack(int, int, int);
int ans[8];
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int n,m; cin>>n>>m;
	backtrack(n, m, 0);
	return 0;
}
void backtrack(int n, int m, int index) {
	if(index==m) {
		for(int j=0; j<m; j++) {
			cout<<ans[j]<<' ';
		}
		cout<<'\n';
		return;
	}
	for(int i=1; i<=n; i++) {
		ans[index]=i;
		if(ans[index-1]<=ans[index]) //그 전 인덱스의 크기보다 크거나 같을때만 탐색
			backtrack(n, m, index+1);
	} //index++ 하지않음에 유의, index가 재귀함수호출 반환과정에서 통제불가능하게 늘어남
}
