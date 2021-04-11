#include <iostream>
using namespace std;
int main(void) {
    //cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
    int n; cin>>n;
    int Fib[1001];
    Fib[1]=1; Fib[2]=2;
    for(int i=3; i<1001; i++) {
        Fib[i]=(Fib[i-2]+Fib[i-1])%10007;
    } //피보나치가 1000만 되도 매우커서 중간에 나눠주는게 포인트
    cout<<Fib[n];
    return 0; //나머지 연산은 중간에 나눈값을 연산해도 유효함
} //타일링 점화식이 피보나치