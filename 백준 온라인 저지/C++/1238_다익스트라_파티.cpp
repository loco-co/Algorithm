#include <iostream>
#include <queue>
#define max 1001
#define Inf 1e9
using namespace std;
int n,m,x;
int dist[max];
int distx[max]; //x로부터 모든 마을까지의 거리 
vector<pair<int, int>> graph[max];
priority_queue<pair<int, int>> pq;
void dijkstra();
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	cin>>n>>m>>x;
	int i,j,w,res; int ans=0;
	for(int k=0; k<m; k++) {
		cin>>i>>j>>w;
		graph[i].push_back({j,w});
	}
	for(int k=1; k<=n; k++) {
		dist[k]=Inf;
	}
	dist[x]=0;
	pq.push({0,x});
	dijkstra();
	
	for(int k=1; k<=n; k++) {
		distx[k]=dist[k]; //결과 저장 
	}
	
	for(int k=1; k<=n; k++) { //한 마을로부터 x까지, 모든 마을만큼 반복 
		for(int a=1; a<=n; a++) {
			dist[a]=Inf;
		}
		dist[k]=0;
		pq.push({0,k});
		dijkstra();
		res=dist[x]+distx[k]; //가는 시간+돌아오는 시간 
		if(res>ans) { ans=res; } //최댓값 갱신 
	}
	cout<<ans;
	return 0;
}
void dijkstra() {
	while(!pq.empty()) {
		int cost=-pq.top().first;
		int here=pq.top().second; pq.pop();
		if(cost>dist[here]) {
			continue;
		}
		for(int i=0; i<graph[here].size(); i++) {
			int ncost=cost + graph[here][i].second;
			int there=graph[here][i].first;
			if(dist[there]>ncost) {
				dist[there]=ncost;
				pq.push({-ncost, there});
			}
		}
	}
}
