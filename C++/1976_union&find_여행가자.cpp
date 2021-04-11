#include <iostream>
using namespace std;
int hub[201];
int find(int);
void Union(int, int);
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int n,m,k; cin>>n>>m;
	for(int i=1; i<=200; i++) {
		hub[i]=i;
	} //���� ���� �ʱ�ȭ 
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin>>k; //����Ǿ� ������ union 
			if(k==1) { Union(i,j); }
		}
	}
	int city; cin>>city;
	int rootcity=find(city); //1��° ������ ���չ�ȣ 
	bool plan=true;
	for(int i=1; i<m; i++) {
		cin>>city;
		if(find(city)!=rootcity) { //��� �� ���ö� ����Ǿ� ���� ������ 
			plan=false; //��ȹ�� ���� 
			break; 
		}
	}
	if(plan) { cout<<"YES"; } //�־��� ���õ��� ��� ���� ���� 
	else { cout<<"NO"; }
	return 0;
}
int find(int city) {
	if(hub[city]==city) { return city; }
	else {
		int nextcity=hub[city];
		return hub[city]=find(nextcity);
	}
}
void Union(int a, int b) {
	if(find(a)==find(b)) { return; }
	else { hub[find(b)]=find(a); return; }
}
