#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int chef[5]={}; //0���� �ʱ�ȭ�� 
	int winner,s; int score=0;
	for(int i=0; i<5; i++) {
		for(int j=0; j<4; j++) {
			cin>>s; chef[i]+=s;
			if(score<chef[i]) { //���� �ִ������� �̺��� ������ 
				winner=i+1; //����� ���� 
				score=chef[i]; //���� ���� 
			}
		}
	}
	cout<<winner<<' '<<score;
	return 0;
}
