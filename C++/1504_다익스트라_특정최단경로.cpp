#include <iostream>
#include <queue>
#define INF 800000 //800*1000 ��ѱ����� ���� 
using namespace std;
int n,e,v1,v2;
vector <pair<int,int>> graph[801];
priority_queue<pair<int,int>> pq;
int dist[801];
void preset(int);
void dijkstra();
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	cin>>n>>e;
	int i,j,c;
	for(int k=0; k<e; k++) {
		cin>>i>>j>>c;
		graph[i].push_back({j,c});
		graph[j].push_back({i,c});
	}
	cin>>v1>>v2;
	
	preset(1);
	dijkstra();
	int v1first1=dist[v1]; //1���� v1���� 
	int v2first1=dist[v2]; //1���� v2���� 
	
	preset(v1);
	dijkstra();
	int v1first2=dist[v2]; //v1���� v2���� 
	int v2first3=dist[n]; //v1���� n���� 
	
	preset(v2);
	dijkstra();
	int v1first3=dist[n]; //v2���� n���� 
	int v2first2=dist[v1]; //v2���� v1���� 
	
	int ans=min(v1first1 + v1first2 + v1first3, v2first1 + v2first2 + v2first3);
	//���� s v1 v2 n�� s v2 v1 n�� ���� �� 
	if(ans>=INF) { //���� �����ϴ� �� �߿� INF�� �ϳ��� ���Ե� ������  
		cout<<-1; //���� ���� �� 
	}
	else cout<<ans; //1e9=1,000,000,000 �����÷ο쿡 ���� 
	return 0; //int�� 21�� 
}
void preset(int s) {
	for(int i=1; i<=n; i++) {
		dist[i]=INF;
	}
	dist[s]=0; pq.push({0,s});
	return;
}
void dijkstra() {
	while(!pq.empty()) {
		int cost=-pq.top().first;
		int here=pq.top().second; pq.pop();
		if(dist[here]<cost) { continue; }
		
		for(int i=0; i<graph[here].size(); i++) {
			int there=graph[here][i].first;
			int ncost=cost + graph[here][i].second;
				if(ncost<dist[there]) {
					dist[there]=ncost;
					pq.push({-ncost,there});
				}
		}
	}
	return;
}
//v2���ٰ� v1���°� �Ҽ��� ���� 
