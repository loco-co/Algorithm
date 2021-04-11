#include <iostream>
using namespace std;
int Gate[100001];
int docking;
int find(int);
void Union(int, int);
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int g,p; cin>>g>>p;
	for(int i=0; i<=g; i++) {
		Gate[i]=i;
	} //����Ʈ�� ���� 
	for(int i=0; i<p; i++) {
		int k; cin>>k;
		int node=find(k);
		if(node==0) { break; } //��ŷ�Ұ� ����, �Է��� �� ���� �ʾƵ� �� 
		else {
			docking++; //node, �� �� �� �ִ� �ִ�ū���� ����Ʈ�� ��ŷ�ϰ� 
			Union(node-1, node); //���� �� �� �ٷ� -1�� ���ؿ� �ٿ����� 
		} //�� ����Ʈ�� ã���� �ð��� �پ��� 
	}
	cout<<docking;
	return 0;
}
int find(int a) {
	if(Gate[a]==a) { return a; }
	else 
		return Gate[a]=find(Gate[a]);
}
void Union(int a, int b) {
	if(find(a)==find(b)) return;
	else {
		Gate[find(b)]=find(a);
		return;
	}
}
