#include <iostream>
#include <queue>
using namespace std;
vector<pair<int,int>> graph[10001];
priority_queue<pair<int,int>> pq;
bool set[10001]; //mst�� ���ԵǾ����� ���� 
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
	for(int i=0; i<graph[1].size(); i++) { //1���� ���տ� ���Խ�Ű�� Ȯ�� ���� 
		int node=graph[1][i].first;
		int cost=graph[1][i].second;
		pq.push({-cost,node}); //prioirty queue�� ù��° ���Ҹ� �������� ��(�߿�) 
	}
	set[1]=true;
	mst();
	cout<<ans;
	return 0;
}
void mst() {
	while(!pq.empty()) { //��� ������ ���Ե� �� ���� ��� ������ �� 
		int next=pq.top().second; //�� �� �ִ� ������ ���� �� ���� 
		int ncost=-pq.top().first; pq.pop();
		if(!set[next]) { //���տ� ���Ե����� ������ 
			set[next]=true; //������ �߰� 
			ans += ncost;
			for(int i=0; i<graph[next].size(); i++) { //���� �߰��� �������κ��� 
				int node=graph[next][i].first; //�����ִ� ��� ������ pq�� �߰� 
				int cost=graph[next][i].second;
				pq.push({-cost,node});
			}
		}
	}
	return;
}
