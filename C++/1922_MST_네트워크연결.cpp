#include <iostream>
#include <queue>
using namespace std;
vector<pair<int,int>> graph[1001];
priority_queue<pair<int,int>> pq;
bool set[1001]; //프림 알고리즘 
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int n,m; cin>>n>>m;
	int a,b,c; int sum=0;
	for(int i=0; i<m; i++) {
		cin>>a>>b>>c;
		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
	}
	for(int i=0; i<graph[1].size(); i++) { //임의의 점은 1로 선택 
		int v=graph[1][i].first;
		int c=graph[1][i].second;
		pq.push({-c,v});
	}
	set[1]=true;
	while(!pq.empty()) {
		int cost=-pq.top().first; //제일 싼 간선 
		int next=pq.top().second; pq.pop(); //싸이클을 형성하지 않게 
		if(!set[next]) { //집합에 포함되지 않은 정점일때만 
			set[next]=true; //포함시키고 
			sum += cost;
			for(int i=0; i<graph[next].size(); i++) { //추가로 갈 수 있게된 
				int v=graph[next][i].first; //간선들 pq에 넣음 
				int c=graph[next][i].second;
				pq.push({-c,v});
			}
		}
	}
	cout<<sum;
	return 0;
}
