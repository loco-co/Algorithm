#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int chef[5]={}; //0으로 초기화됨 
	int winner,s; int score=0;
	for(int i=0; i<5; i++) {
		for(int j=0; j<4; j++) {
			cin>>s; chef[i]+=s;
			if(score<chef[i]) { //현재 최대점수가 이보다 작으면 
				winner=i+1; //우승자 갱신 
				score=chef[i]; //점수 갱신 
			}
		}
	}
	cout<<winner<<' '<<score;
	return 0;
}
