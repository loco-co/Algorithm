#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	long long n,k;
	while(cin>>n>>k) {
		long long chicken=n; //ó������ ��������(��� 1����)�� ��Ŵ 
		while(n/k>0) { //��ų �� ���������� 
			long long q=n/k; //����k���� ����1�� 
			chicken += q;
			n=q + n%k; //���Ѽ� �ٽ� ���� ���� + k���� �ȵǼ� ���� ���� 
		} //Ʋ������ ������ ���� ��Ƽ� ����������� 
		cout<<chicken<<'\n';
	}
	return 0;
}
//while (cin >> a >> b) 
//������ �д� ���� �������� ���,
//stream ��ü�� �����ߴٴ� ǥ�ø� �ϰ� �˴ϴ�. 
//���� ǥ�ð� �� stream ��ü�� bool �� �ʿ��� ���ƿ��� 
//false�� �򰡵˴ϴ�. 
