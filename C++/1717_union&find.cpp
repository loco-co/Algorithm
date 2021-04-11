#include <iostream>
#define max 1000001
using namespace std;
int root[max]; //조상을 저장하는 배열 
int find(int);
void Union(int, int);
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int n,m; cin>>n>>m;
	int x,a,b;
	for(int i=0; i<max; i++) {
		root[i]=i; //모든 원소는 각자의 집합으로 초기화 
	}
	for(int i=0; i<m; i++) {
		cin>>x>>a>>b;
		if(x==0) { //union
			Union(a,b);
		}
		else { //find
			int roota=find(a);
			int rootb=find(b);
			if(roota==rootb) { cout<<"YES"<<'\n'; } //바로 대입하는 방법도 있다 
			else { cout<<"NO"<<'\n'; } 
		}
	}
	return 0;
}
int find(int x) {
	if(root[x]==x) { return x; } //조상만 인덱스와 원소가 같음 
	else {
		return root[x]=find(root[x]); //올라간 경로에 위치한 노드들 전부 조상으로 업데이트 
	} //find compression 
}
void Union(int x, int y) {
	int rootx=find(x);
	int rooty=find(y); //비교해서 작은 번호가 조상이 되게 할 수도 있다 
	
	root[rooty]=rootx; //틀린 곳, 주의 
	return;
}
