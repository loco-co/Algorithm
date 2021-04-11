#include <iostream>
#define max 123456*2
using namespace std;
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	while(1) {
		int n; cin>>n;
		if(n==0) { break; }
		bool prime[max+1];
		for(int i=0; i<=max; i++) {
			prime[i]=true;
		}
		
		for(int i=2; i<=max/2; i++) { //에라토스테네스의 체의 방법으로 
			int k = i*2; //최대범위까지 소수를 구하는 과정 
			while(k<=max) {
				prime[k]=false;
				k += i;
			}
		}
		
		int count=0;
		for(int i=n+1; i<=2*n; i++) { //범위에 맞게 
			if(prime[i]) { count++; } //소수로 체크된 수를 구해주는 과정 
		}
		cout<<count<<'\n';
	}
	return 0;
}
