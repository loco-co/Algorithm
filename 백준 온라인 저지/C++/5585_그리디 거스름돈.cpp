#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int p; cin>>p;
	int charge=1000 - p;
	int count=0; int i=0;
	int e[6]={500,100,50,10,5,1}; //��ȭ 
	while(charge>0) { //while���� �ݼ�: ~���� �ݺ�
		if(charge>=e[i]) { //�׼��� ū �ܵ����� 
			charge -= e[i];
			count++;
		}
		else {
			i++;
		}
	}
	cout<<count;
	return 0;
}
