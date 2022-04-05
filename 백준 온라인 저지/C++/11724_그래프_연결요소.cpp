#include <iostream>
#include <vector>
using namespace std;
vector<int> graph[1001];
bool visit[1001];
void dfs(int a);
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int n,m; cin>>n>>m;
	for(int i=0; i<m; i++) {
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int cpnt=0;
	for(int i=1; i<=n; i++) {
		if(!visit[i]) { //모든 노드에 대해서 도는데 
		dfs(i); //dfs하는 결과 
		cpnt++; //처음 방문하는 건 컴포넌트 
		}
	}
	cout<<cpnt;
	return 0;
}
void dfs(int a) {
	for(int i=0; i<graph[a].size(); i++) { //이어진 모든 vertex에 대해서 
		if(!visit[graph[a][i]]) { //방문한 적 없으면 
			visit[graph[a][i]]=1; //방문만 하고 
			dfs(graph[a][i]);
		}
	}
}
