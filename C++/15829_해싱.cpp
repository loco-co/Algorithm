#include <iostream>
using namespace std;
int main(void) {
    //cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
    long long n,sum=0; cin>>n;
    string a; cin>>a;
    long long temp=1;
    for(int i=0; i<n; i++) {
        int alpha=a[i]-'a'+1;
        sum += alpha*temp;
        sum = sum%1234567891;
        
        temp *= 31;
        temp = temp%1234567891; //연산때마다 나눠주기
    }
    cout<<sum;
    return 0;
} //hash는 계산과정중 수가 매우 커진다. 따라서 연산때마다 나눠줘야한다