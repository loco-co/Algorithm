#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int d,k; cin>>d>>k;
	int X[31]; int Y[31];
	X[1]=1; X[2]=0;
	Y[1]=0; Y[2]=1;
	for(int i=3; i<31; i++) {
		X[i] = X[i-2] + X[i-1];
		Y[i] = Y[i-2] + Y[i-1];
	} //d일에 필요한 a,b의 계수 계산 
	int ca=X[d]; int cb=Y[d];
	int a=1; int b;
	while(true) { //떡 k개를 나누어 떨어지게 구성하는 a와 b찾기 
		int q = k-a*ca; //a를 1부터 브루트포스하게 찾는다 
		if(q % cb==0) { //b로도 나누어 떨어지면 
			b = q/cb; //그 b가 정답 
			break;
		}
		a++;
	}
	cout<<a<<'\n'<<b;
	return 0;
}
