#include <iostream>
#include <queue>
#define max 20001
#define inf 3000000
using namespace std;
int V,E,start;
vector<pair<int, int>> graph[max];
priority_queue<pair<int, int>> pq; //최소비용, 해당정점까지의 pair 
int dist[max]; //인덱스 정점까지의 최소비용 저장 
void update();
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	cin>>V>>E>>start;
	int i,j,w;
	for(int n=0; n<E; n++) {
		cin>>i>>j>>w;
		graph[i].push_back({j,w});
	}
	for(int i=1; i<=V; i++) {
		dist[i]=inf;
	}
	pq.push(make_pair(0, start)); //시작지점부터 갱신 시작 
	dist[start]=0;
	update();
	for(int i=1; i<=V; i++) {
		if(dist[i]==inf) {
			cout<<"INF"<<'\n';
		}
		else cout<<dist[i]<<'\n';
	}
	return 0;
}
void update() {
	while(!pq.empty()) {
		int cost=-pq.top().first; //pq에 마이너스로 저장하고 받아서 최소 힙 
		int here=pq.top().second; pq.pop(); //pq에서는 시작지점부터 제일 짧은 노드부터 뽑아냄 
		if(dist[here]<cost) { //이것보다 이미 최소로 갱신한 노드이면 
			continue; //패스 
		}
		for(int i=0; i<graph[here].size(); i++) { //인접한 모든 노드들에 대해 
			int there=graph[here][i].first; //다음 노드 
			int ncost=cost + graph[here][i].second; //여기까지 최소비용에 추가비용을 더한 값이 
			if(ncost<dist[there]) { //현재 저장된 값보다 작으면 
				dist[there]=ncost; //갱신하고 
				pq.push(make_pair(-ncost, there)); //pq에 넣음 
			}
		}
	}
}
