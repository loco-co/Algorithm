#include <iostream>
#include <queue>
using namespace std;
vector<pair<int,int>> graph[10001];
priority_queue<pair<int,int>> pq;
bool set[10001]; //mst에 포함되었는지 여부 
int v,e,ans;
void mst();
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	cin>>v>>e;
	int i,j,w;
	for(int k=0; k<e; k++) {
		cin>>i>>j>>w;
		graph[i].push_back({j,w});
		graph[j].push_back({i,w});
	}
	for(int i=0; i<graph[1].size(); i++) { //1부터 집합에 포함시키고 확장 시작 
		int node=graph[1][i].first;
		int cost=graph[1][i].second;
		pq.push({-cost,node}); //prioirty queue는 첫번째 원소를 기준으로 함(중요) 
	}
	set[1]=true;
	mst();
	cout<<ans;
	return 0;
}
void mst() {
	while(!pq.empty()) { //모든 정점이 포함될 때 까지 모든 간선을 평가 
		int next=pq.top().second; //갈 수 있는 간선중 제일 싼 간선 
		int ncost=-pq.top().first; pq.pop();
		if(!set[next]) { //집합에 포함되있지 않으면 
			set[next]=true; //간선을 추가 
			ans += ncost;
			for(int i=0; i<graph[next].size(); i++) { //새로 추가된 정점으로부터 
				int node=graph[next][i].first; //갈수있는 모든 간선을 pq에 추가 
				int cost=graph[next][i].second;
				pq.push({-cost,node});
			}
		}
	}
	return;
}
