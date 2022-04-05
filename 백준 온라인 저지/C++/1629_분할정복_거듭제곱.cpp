#include <iostream>
using namespace std;
int divide(int, int, int);
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int a,b,c; cin>>a>>b>>c;
	int ans = divide(a,b,c);
	cout<<ans % c; //주어진 b가 1일때도 처리 
	return 0;
}
int divide(int a, int b, int c) {
	if(b==1) { return a; }
	long long temp = divide(a, b/2, c); //b는 0일때 1리턴해도 상관없음 
	if(b % 2==0) { 
		return temp % c * temp % c;
	}
	else { //b가 홀수이면 2로 나눈걸 2번곱하고 1번 더 곱해주면 된다 
		return (temp % c * temp % c) * a % c;
	} //구하는 과정에서 몇 번이든 어느 수든 나눠도 되는 나누기 성질 이용 
}
