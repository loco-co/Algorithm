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
	if(visit[v]) { return; } //�湮������ ���ư� 
	else {
		cout<<v<<" "; //�湮�������� 
		visit[v]=true; //����ϰ� �湮�ϰ� 
		for(int i=0; i<graph[v].size(); i++) {
			DFS(graph[v][i]); //���� ��ȣ���� dfs 
		}
	}
}

void BFS() {
	int a=q.front(); q.pop(); //q�� �տ�������(ù��°�� s) Ž������ 
	for(int i=0; i<graph[a].size(); i++) {
		int t=graph[a][i]; //a�� ������� �� ���� ��ȣ���� 
		if(visit[t]==false) { //�湮�������� 
			q.push(t);
			visit[t]=true; //q�� �ְ� �湮ǥ�� 
			cout<<t<<" ";
		}
	}
	if(!q.empty()) { BFS(); } //q�� �� ������ bfs 
}
