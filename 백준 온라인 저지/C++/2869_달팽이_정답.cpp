#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int up,down,v; int days=0;
	cin>>up>>down>>v;
	int dist=up-down; //�Ϸ翡 �ö󰡴� �� 
	int newv=v-up; days++; //������ ���� �����ϱ⸸ �ϸ�� 
	days += newv/dist; //ù������ ������ �� �������� �ɸ� �� 
	if(newv%dist) { //�������� ������ +1 
		days++;
	}
	cout<<days;
	return 0;
}
