#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int a,b; cin>>a>>b;
	int sum[2000]; //넉넉하게 해야 
	int i=1; int k=1;
	while(i<1000) {
		for(int j=0; j<k; j++) {
			sum[i]=sum[i-1]+k;
			i++;
		}
		k++;
	} //구간 합 저장 
	cout<<sum[b]-sum[a-1];
	return 0;
}
