#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> graph[101];
bool visit[101]={};
int cnt=0;
void dfs(int);
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int a,b;
	for(int i=0; i<m; i++) {
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	cout<<cnt-1;
	return 0;
}

void dfs(int v) {
	if(visit[v]) { return; }
	cnt++; //dfs하면서 연결된 노드를 방문할때마다 감염+1 
	visit[v]=true;
	for(int i=0; i<graph[v].size(); i++) {
		dfs(graph[v][i]);
	}
}
