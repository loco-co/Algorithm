#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int smallest=64;
	int sum=64; int cnt=1;
	int x; cin>>x;
	while(sum!=x) { //합이 x보다 크면 
		int half=smallest/2; //가장 짧은 막대를 반으로 자른다 
		if(sum-half>=x) { //그것의 반을 버리고 남은 sum이 x보다 크거나 같으면 
			sum -= half; //정말로 그것을 버린다. 
			smallest=half; //틀린이유, 이 때 반으로 자른 1개가 남아있으므로 
		} //가장 짧은 막대가 갱신된다 
		else { smallest=half; cnt++; } //버리고 x보다 작아진다면 버리지 않음 
	} //따라서 막대의 수가 1개 증가한다 
	cout<<cnt;
	return 0;
}
