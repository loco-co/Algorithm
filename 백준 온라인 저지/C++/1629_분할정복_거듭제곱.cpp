#include <iostream>
using namespace std;
int divide(int, int, int);
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int a,b,c; cin>>a>>b>>c;
	int ans = divide(a,b,c);
	cout<<ans % c; //�־��� b�� 1�϶��� ó�� 
	return 0;
}
int divide(int a, int b, int c) {
	if(b==1) { return a; }
	long long temp = divide(a, b/2, c); //b�� 0�϶� 1�����ص� ������� 
	if(b % 2==0) { 
		return temp % c * temp % c;
	}
	else { //b�� Ȧ���̸� 2�� ������ 2�����ϰ� 1�� �� �����ָ� �ȴ� 
		return (temp % c * temp % c) * a % c;
	} //���ϴ� �������� �� ���̵� ��� ���� ������ �Ǵ� ������ ���� �̿� 
}
