#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	long long n,k;
	while(cin>>n>>k) {
		long long chicken=n; //처음가진 쿠폰으로(장당 1마리)로 시킴 
		while(n/k>0) { //시킬 수 있을때까지 
			long long q=n/k; //도장k개당 쿠폰1장 
			chicken += q;
			n=q + n%k; //시켜서 다시 얻은 도장 + k개가 안되서 남은 도장 
		} //틀린이유 나머지 끼리 모아서 사먹을수있음 
		cout<<chicken<<'\n';
	}
	return 0;
}
//while (cin >> a >> b) 
//데이터 읽는 것이 실패했을 경우,
//stream 객체에 실패했다는 표시를 하게 됩니다. 
//실패 표시가 된 stream 객체는 bool 이 필요한 문맥에서 
//false로 평가됩니다. 
