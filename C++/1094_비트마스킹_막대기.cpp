#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int smallest=64;
	int sum=64; int cnt=1;
	int x; cin>>x;
	while(sum!=x) { //���� x���� ũ�� 
		int half=smallest/2; //���� ª�� ���븦 ������ �ڸ��� 
		if(sum-half>=x) { //�װ��� ���� ������ ���� sum�� x���� ũ�ų� ������ 
			sum -= half; //������ �װ��� ������. 
			smallest=half; //Ʋ������, �� �� ������ �ڸ� 1���� ���������Ƿ� 
		} //���� ª�� ���밡 ���ŵȴ� 
		else { smallest=half; cnt++; } //������ x���� �۾����ٸ� ������ ���� 
	} //���� ������ ���� 1�� �����Ѵ� 
	cout<<cnt;
	return 0;
}
