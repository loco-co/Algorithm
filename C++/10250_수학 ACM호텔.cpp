#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int t; cin>>t;
	int H,W,N,roomno,x,y;
	for(int i=0; i<t; i++) {
		cin>>H>>W>>N;
		if(N%H==0) { //N이 층으로 나누어 떨어지면 
			x=N/H; // 그 열
			y=H; //층수 그대로 배정 
		} //즉, 그 열의 마지막 방 
		else {
			x=N/H+1; // 그 다음 열 
			y=N%H; //층수는 나머지 
		}
		roomno=y*100+x;
		cout<<roomno<<'\n';
	}
	return 0;
}
