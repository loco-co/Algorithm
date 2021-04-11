#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int t,n; cin>>t;
	while(t--) {
		cin>>n;
		int s[n]; int m[n]; bool survive[n];
		int surv=n; //전체 인원 생존 
		for(int i=0; i<n; i++) {
			cin>>s[i]>>m[i];
			survive[i]=true;
		}
		for(int i=0; i<n; i++) {
			if(survive[i]) { //살아남은 사원을 기준으로 
				for(int j=0; j<n; j++) {
					if(survive[j] && s[j]>s[i] && m[j]>m[i]) { //살아남았는데 s와 m등수가 기준보다 모두 큰 사원은 
						survive[j]=false; //제외하고 
						surv--; //인원 차감 
					}
				}
			}
		}
		cout<<surv<<'\n';
	}
	return 0;
}
