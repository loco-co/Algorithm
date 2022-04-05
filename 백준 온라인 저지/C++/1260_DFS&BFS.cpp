#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
void DFS(int);
void BFS();
bool visit[1001]={};
vector<int> graph[1001];
queue<int> q;
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int n,m,s; cin>>n>>m>>s;
	int a,b;
	for(int i=0; i<m; i++) {
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i=0; i<n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	
	DFS(s);
	cout<<'\n';
	for(int i=0; i<1001; i++) {
		visit[i]=0;
	}
	
	q.push(s); cout<<s<<" "; visit[s]=true;
	BFS();
	return 0;
}

void DFS(int v) {
	if(visit[v]) { return; } //방문했으면 돌아감 
	else {
		cout<<v<<" "; //방문안했으면 
		visit[v]=true; //출력하고 방문하고 
		for(int i=0; i<graph[v].size(); i++) {
			DFS(graph[v][i]); //빠른 번호부터 dfs 
		}
	}
}

void BFS() {
	int a=q.front(); q.pop(); //q의 앞에서부터(첫번째는 s) 탐색시작 
	for(int i=0; i<graph[a].size(); i++) {
		int t=graph[a][i]; //a의 인접노드 중 빠른 번호부터 
		if(visit[t]==false) { //방문안했으면 
			q.push(t);
			visit[t]=true; //q에 넣고 방문표시 
			cout<<t<<" ";
		}
	}
	if(!q.empty()) { BFS(); } //q가 빌 때까지 bfs 
}
