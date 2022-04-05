#include <iostream>
using namespace std;
int cnt,op[10],visit[10],A[11];
int minv=1e9;
int maxv=-1e9; //틀린 이유,,최댓값이 -1일 수도
void solve(int, int, int);
int main(void) {
    //cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
    int n,k; cin>>n;
    for(int i=0; i<n; i++) {
        cin>>A[i];
    }
    for(int i=1; i<=4; i++) { //+1 -2 *3 /4
        cin>>k;
        for(int j=0; j<k; j++) {
            op[cnt]=i; cnt++; //op[]에 저장
        }
    }
    solve(n, 0, 0);
    cout<<maxv<<'\n'<<minv;
    return 0;
}
void solve(int n, int index, int val) { //n은 사이즈, index는 현재 차수 (현재 쓴 연산자의 갯수)
    if(index==0) { val=A[0]; } //맨 처음 val은 수열의 첫 번째 숫자
    if(index==n-1) { //연산자 다 썼으면
        if(val>maxv) { maxv=val; }
        if(val<minv) { minv=val; }
        return;
    }
    for(int i=0; i<n-1; i++) {
        if(visit[i]) { continue; } //방문한 적 있으면 skip
        visit[i]=1; //방문한 적 없으면
        if(op[i]==1) {
            val=val+A[index+1];
        }
        if(op[i]==2) {
            val=val-A[index+1];
        }
        if(op[i]==3) {
            val=val*A[index+1];
        }
        if(op[i]==4) { //음수 나눗셈은 c++에서 알아서 처리
            val=val/A[index+1];
        }
        solve(n, index+1, val); //바뀐 val로 재귀 진입
        visit[i]=0;
        if(op[i]==1) { //중요,,나올 때 값을 원상복귀 시켜줘야함
            val=val-A[index+1];
        }
        if(op[i]==2) {
            val=val+A[index+1];
        }
        if(op[i]==3) {
            val=val/A[index+1];
        }
        if(op[i]==4) {
            val=val*A[index+1];
        }
    }
}