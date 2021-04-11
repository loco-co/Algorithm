#include <iostream>
#include <algorithm> //abs()
using namespace std;
int start,link,S[21][21],smem[11];
bool visit[21];
int ans=1e5;
void solve(int, int);
int main(void) {
    //cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
    int n; cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>S[i][j];
    solve(n,1);
    cout<<ans;
    return 0;
}
void solve(int n, int degree) {
    if(degree==n/2+1) {
        for(int i=1; i<=n; i++) {
            for(int j=i+1; j<=n; j++) { //j는 i+1부터 시작해서 루프를 거의 절반으로 줄임
                if(visit[i] && visit[j]) { //i와j가 start팀이면(지나온 적 있으면)
                    start += S[i][j];
                    start += S[j][i];
                }
                else if(!visit[i] && !visit[j]) { //둘 다 link팀이면
                    link += S[i][j];
                    link += S[j][i];
                }
            }
        }
        if(abs(start-link) < ans) { //총 합의 차이, 즉 절댓값이 현재 최소 차이보다 작으면
            ans=abs(start-link); //그 절댓값 차이로 업데이트
        }
        start=0; link=0; //다시 초기화
        return;
    }
    for(int i=1; i<=n; i++) {
        if(i>smem[degree-1]) { //전에 지나온 숫자보다 크게하여
            visit[i]=1; // 중복을 제거해야함, 틀린 이유
            smem[degree]=i; //start멤버에 포함
            solve(n, degree+1);
            smem[degree]=0;
            visit[i]=0;
        }
    }
}