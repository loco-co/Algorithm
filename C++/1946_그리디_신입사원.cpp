#include <iostream>
#include <algorithm>
using namespace std;
struct applicant {
	int s; //���� ��� 
	int m; //���� ��� 
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
		sort(list, list+n, cmp); //���� ���� ����� ���� 
		int surv=1; int mostm=list[0].m; //���� ū ���� ����� ó���� ����1���� ���� ����̰�, 
		for(int i=0; i<n; i++) { //������� ������ �������� ���ϸ鼭 ���ŵ� 
			if(list[i].m<mostm) { //��������� �� �����ٴ� �۾ƾ� ���� 
				surv++; mostm=list[i].m;
			}
		}
		cout<<surv<<'\n';
	}
}
//if(a.s<b.s) { return true; }
	//else { return false; } �� ���� 
//������� Ȯ���� ����� �� ���� ���� ���� ����� ���� 
//��� �� �� �� ���� ���� ����� �����ϸ� ���س����� ������� 
//������ �� for���� ��°�� ����� ���� �����մϴ�.
