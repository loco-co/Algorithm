#include <iostream>
#include <queue>
#define max 1001
#define inf 100000000
using namespace std;
int V,E,s,d;
int dist[max];
vector<pair<int, int>> graph[max];
priority_queue<pair<int, int>> pq;
void dijkstra();
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	cin>>V>>E;
	int i,j,w;
	for(int n=0; n<E; n++) {
		cin>>i>>j>>w;
		graph[i].push_back({j,w});
	}
	cin>>s>>d;
	for(int i=1; i<=V; i++) {
		dist[i]=inf;
	}
	dist[s]=0; //시작이 1번이라는 보장 x 
	pq.push(make_pair(0,s));
	dijkstra();
	cout<<dist[d]; //단일 도착지 
	return 0;
}
void dijkstra() {
	while(!pq.empty()) {
		int cost=-pq.top().first;
		int here=pq.top().second; pq.pop();
		if(dist[here]<cost) {
			continue;
		}
		for(int i=0; i<graph[here].size(); i++) {
			int there=graph[here][i].first;
			int ncost=cost + graph[here][i].second;
			if(ncost<dist[there]) {
				dist[there]=ncost;
				pq.push(make_pair(-ncost, there));
			}
		}
	}
}
