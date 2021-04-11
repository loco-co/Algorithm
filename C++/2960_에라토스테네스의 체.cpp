#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int n,k; cin>>n>>k;
	int count=0;
	int arr[n+1];
	for(int i=2; i<=n; i++) {
		arr[i]=i;
	}
	for(int i=2; i<=n; i++) {
		if(arr[i]==i) { //아직 지워지지 않은 소수에 대해 
			for(int t=i; t<=n; t += i) { //t의 배수만큼 반복 
				if(arr[t]==t) { //t의 배수가 아직 걸러지지 않았으면 
					arr[t]=0; //거르고 
					count++; //횟수 증가 
					if(count==k) {
						cout<<t; return 0;
					}
				}
			}
		}
	}
}
