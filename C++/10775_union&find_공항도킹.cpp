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
	} //게이트를 노드로 
	for(int i=0; i<p; i++) {
		int k; cin>>k;
		int node=find(k);
		if(node==0) { break; } //도킹할곳 없음, 입력을 다 읽지 않아도 됨 
		else {
			docking++; //node, 즉 할 수 있는 최대큰수의 게이트에 도킹하고 
			Union(node-1, node); //노드는 그 수 바로 -1의 노드밑에 붙여놓음 
		} //빈 게이트를 찾을때 시간이 줄어든다 
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
