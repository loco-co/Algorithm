#include <iostream>
#include <algorithm>
using namespace std;
struct applicant {
	int s; //서류 등수 
	int m; //면접 등수 
};
bool cmp(applicant a, applicant b) {
	return a.s<b.s;
}
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		applicant list[n];
		for(int i=0; i<n; i++) {
			cin>>list[i].s>>list[i].m;
		}
		sort(list, list+n, cmp); //먼저 서류 등수로 정렬 
		int surv=1; int mostm=list[0].m; //제일 큰 면접 등수는 처음엔 서류1등의 면접 등수이고, 
		for(int i=0; i<n; i++) { //서류등수 순으로 내려가며 비교하면서 갱신됨 
			if(list[i].m<mostm) { //면접등수는 그 값보다는 작아야 생존 
				surv++; mostm=list[i].m;
			}
		}
		cout<<surv<<'\n';
	}
}
//if(a.s<b.s) { return true; }
	//else { return false; } 도 가능 
//현재까지 확인한 사원들 중 가장 높은 면접 등수를 가진 
//사원 단 한 명에 대한 면접 등수만 저장하며 비교해나가는 방식으로 
//내부의 비교 for문을 통째로 지우는 것이 가능합니다.
