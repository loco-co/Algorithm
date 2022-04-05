#include <iostream>
#include <queue>
#define max 1001
#define Inf 1e9
using namespace std;
int n,m,x;
int dist[max];
int distx[max]; //x�κ��� ��� ���������� �Ÿ� 
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
		distx[k]=dist[k]; //��� ���� 
	}
	
	for(int k=1; k<=n; k++) { //�� �����κ��� x����, ��� ������ŭ �ݺ� 
		for(int a=1; a<=n; a++) {
			dist[a]=Inf;
		}
		dist[k]=0;
		pq.push({0,k});
		dijkstra();
		res=dist[x]+distx[k]; //���� �ð�+���ƿ��� �ð� 
		if(res>ans) { ans=res; } //�ִ� ���� 
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
