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
	int vote[N]={}; //��ǥ��
	
	for(int i=0; i<M; i++) { //1���� ��ġ
		int j=0;
		while(A[j] > B[i]) { //����� ũ��
			j++; //�н�
		}
		vote[j] = vote[j] + 1; //����� �۰ų� ������ ��ǥ
	}
	
	int ans=0;
	for(int i=1; i<N; i++) {
		if(vote[ans] < vote[i]) {
			ans=i;
		}
	}
	cout<<ans+1; //1��
	return 0;
}
