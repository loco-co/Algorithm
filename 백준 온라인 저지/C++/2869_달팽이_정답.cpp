#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int up,down,v; int days=0;
	cin>>up>>down>>v;
	int dist=up-down; //하루에 올라가는 양 
	int newv=v-up; days++; //마지막 날은 도착하기만 하면됨 
	days += newv/dist; //첫날부터 마지막 날 이전까지 걸린 날 
	if(newv%dist) { //나머지가 있으면 +1 
		days++;
	}
	cout<<days;
	return 0;
}
