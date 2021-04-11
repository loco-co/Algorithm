#include <iostream>
#include <queue>
#define max 100000
using namespace std;
vector<int> tree[max+1]; //트리는 그래프의 특수한 경우. 
queue<int> q;
int parent[max+1]; //노드의 부모를 저장 
void bfs();
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int n; cin>>n;
	int k,j;
	for(int i=0; i<n-1; i++) {
		cin>>k>>j;
		tree[k].push_back(j);
		tree[j].push_back(k);
	}
	q.push(1);
	bfs();
	for(int i=2; i<=n; i++) {
		cout<<parent[i]<<'\n';
	}
	return 0;
}
void bfs() {
	while(!q.empty()) {
		int p=q.front(); q.pop(); //q에서 1개 꺼내서 
		for(int i=0; i<tree[p].size(); i++) {
			int child=tree[p][i]; //연결된 모든 노드들에 대해 
			if(child==parent[p]) { continue; } //그게 부모면 패스하고 
			parent[child]=p; //자식이면 부모를 기록 
			q.push(child); //자식들로 넓이우선탐색 
		}
	}
}
