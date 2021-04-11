#include <iostream>
#include <queue>
#define max 10000
using namespace std;
vector<pair<int,int>> tree[max+1];
int dist[max+1];
queue<int> q;
int ans;
bool visit[max+1];
void bfs();
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int n,k,j,w; cin>>n;
	for(int i=0; i<n-1; i++) {
		cin>>k>>j>>w;
		tree[k].push_back({j,w});
		tree[j].push_back({k,w}); //트리는 양방향 그래프 
	}
	for(int i=1; i<=n; i++) { //1번 노드부터 n번 노드까지 bfs 
		q.push(i); visit[i]=true;
		bfs();
		for(int j=1; j<=n; j++) {
			dist[j]=0;
			visit[j]=false;
		}
	}
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
			}
			q.push(node);
		}
	}
}
