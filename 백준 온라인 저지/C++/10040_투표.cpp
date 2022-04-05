#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int N, M;
	cin>>N>>M;
	int A[N]; int B[M];
	for(int i=0; i<N; i++)
		cin>>A[i];
	for(int i=0; i<M; i++)
		cin>>B[i];
	int vote[N]={}; //투표함
	
	for(int i=0; i<M; i++) { //1개씩 서치
		int j=0;
		while(A[j] > B[i]) { //비용이 크면
			j++; //패스
		}
		vote[j] = vote[j] + 1; //비용이 작거나 같으면 투표
	}
	
	int ans=0;
	for(int i=1; i<N; i++) {
		if(vote[ans] < vote[i]) {
			ans=i;
		}
	}
	cout<<ans+1; //1등
	return 0;
}
