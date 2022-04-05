#include <iostream>
using namespace std;
int in[100001];
int post[100001];
void getPre(int, int, int);
int main(void) {
    //cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
    int n,k; cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>k;
        in[k]=i; //원소를 인덱스로 받기
    } //서치시간을 줄여줌
    for(int j=1; j<=n; j++) {
        cin>>post[j];
    }
    getPre(1,n,n);
    return 0;
}
void getPre(int low, int high, int index) {
    if(low>high) { return; }
    int root=post[index]; //후위의 맨 마지막은 루트
    int middle=in[root]; //루트의 인덱스를 기점으로 쪼개기
    cout<<root<<' '; //전위 순회
    getPre(low, middle-1, index-1-high+middle); //index-1-(쪼갰을때 뒷덩이의 갯수)
    getPre(middle+1, high, index-1);
}