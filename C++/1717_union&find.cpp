#include <iostream>
#define max 1000001
using namespace std;
int root[max]; //������ �����ϴ� �迭 
int find(int);
void Union(int, int);
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int n,m; cin>>n>>m;
	int x,a,b;
	for(int i=0; i<max; i++) {
		root[i]=i; //��� ���Ҵ� ������ �������� �ʱ�ȭ 
	}
	for(int i=0; i<m; i++) {
		cin>>x>>a>>b;
		if(x==0) { //union
			Union(a,b);
		}
		else { //find
			int roota=find(a);
			int rootb=find(b);
			if(roota==rootb) { cout<<"YES"<<'\n'; } //�ٷ� �����ϴ� ����� �ִ� 
			else { cout<<"NO"<<'\n'; } 
		}
	}
	return 0;
}
int find(int x) {
	if(root[x]==x) { return x; } //���� �ε����� ���Ұ� ���� 
	else {
		return root[x]=find(root[x]); //�ö� ��ο� ��ġ�� ���� ���� �������� ������Ʈ 
	} //find compression 
}
void Union(int x, int y) {
	int rootx=find(x);
	int rooty=find(y); //���ؼ� ���� ��ȣ�� ������ �ǰ� �� ���� �ִ� 
	
	root[rooty]=rootx; //Ʋ�� ��, ���� 
	return;
}
