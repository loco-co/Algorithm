#include <iostream>
#include <queue>
#define max 100000
using namespace std;
vector<pair<int,int>> tree[max+1];
int dist[max+1];
queue<int> q;
int ans,v1;
bool visit[max+1];
void bfs();
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int n,v,j,w; cin>>n;
	for(int i=0; i<n; i++) {
		cin>>v;
		while(1) {
			cin>>j;
			if(j==-1) { break; }
			cin>>w;
			tree[v].push_back({j,w});
		}
	}
	q.push(1); visit[1]=true;
	bfs();
	for(int j=1; j<=n; j++) { //fill()로 대체 가능 
		dist[j]=0;
		visit[j]=false;
	}
	q.push(v1); visit[v1]=true;
	bfs();
	cout<<ans;
	return 0;
}
void bfs() {
	while(!q.empty()) {
		int p=q.front(); q.pop();
		for(int i=0; i<tree[p].size(); i++) {
			int node=tree[p][i].first;
			int cost=tree[p][i].second; //연결된 모든 노드들에 대해 
			if(visit[node]) { continue; } //방문한 적 있는 노드는 패스 
			visit[node]=true;
			dist[node]=dist[p]+cost; //다음 node까지 거리는 이 노드까지 거리 + 드는 비용 
			if(ans<dist[node]) { //이 값이 현재 최댓값보다 크면 갱신 
				ans=dist[node];
				v1=node; //제일 먼 거리에 있는 노드도 저장 
			}
			q.push(node);
		}
	}
}
//"아무 점(v)에서 시작해서 가장 먼 점(v1)을 찾고, 
//그 점(v1)에서 가장 먼 점(v2)를 찾으면, 
//v1과 v2 사이의 거리가 트리의 지름이됩니다."
