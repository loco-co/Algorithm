#include <iostream>
#include <queue>
using namespace std;
vector<pair<int,int>> graph[1001];
priority_queue<pair<int,int>> pq;
bool set[1001]; //���� �˰��� 
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
	for(int i=0; i<graph[1].size(); i++) { //������ ���� 1�� ���� 
		int v=graph[1][i].first;
		int c=graph[1][i].second;
		pq.push({-c,v});
	}
	set[1]=true;
	while(!pq.empty()) {
		int cost=-pq.top().first; //���� �� ���� 
		int next=pq.top().second; pq.pop(); //����Ŭ�� �������� �ʰ� 
		if(!set[next]) { //���տ� ���Ե��� ���� �����϶��� 
			set[next]=true; //���Խ�Ű�� 
			sum += cost;
			for(int i=0; i<graph[next].size(); i++) { //�߰��� �� �� �ְԵ� 
				int v=graph[next][i].first; //������ pq�� ���� 
				int c=graph[next][i].second;
				pq.push({-c,v});
			}
		}
	}
	cout<<sum;
	return 0;
}
