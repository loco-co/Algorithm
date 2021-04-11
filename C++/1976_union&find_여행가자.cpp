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
	} //도시 집합 초기화 
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin>>k; //연결되어 있으면 union 
			if(k==1) { Union(i,j); }
		}
	}
	int city; cin>>city;
	int rootcity=find(city); //1번째 도시의 집합번호 
	bool plan=true;
	for(int i=1; i<m; i++) {
		cin>>city;
		if(find(city)!=rootcity) { //어느 한 도시라도 연결되어 있지 않으면 
			plan=false; //계획은 실패 
			break; 
		}
	}
	if(plan) { cout<<"YES"; } //주어진 도시들이 모두 같은 집합 
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
