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
		if(!visit[i]) { //��� ��忡 ���ؼ� ���µ� 
		dfs(i); //dfs�ϴ� ��� 
		cpnt++; //ó�� �湮�ϴ� �� ������Ʈ 
		}
	}
	cout<<cpnt;
	return 0;
}
void dfs(int a) {
	for(int i=0; i<graph[a].size(); i++) { //�̾��� ��� vertex�� ���ؼ� 
		if(!visit[graph[a][i]]) { //�湮�� �� ������ 
			visit[graph[a][i]]=1; //�湮�� �ϰ� 
			dfs(graph[a][i]);
		}
	}
}
