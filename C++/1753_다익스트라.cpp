#include <iostream>
#include <queue>
#define max 20001
#define inf 3000000
using namespace std;
int V,E,start;
vector<pair<int, int>> graph[max];
priority_queue<pair<int, int>> pq; //�ּҺ��, �ش����������� pair 
int dist[max]; //�ε��� ���������� �ּҺ�� ���� 
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
	pq.push(make_pair(0, start)); //������������ ���� ���� 
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
		int cost=-pq.top().first; //pq�� ���̳ʽ��� �����ϰ� �޾Ƽ� �ּ� �� 
		int here=pq.top().second; pq.pop(); //pq������ ������������ ���� ª�� ������ �̾Ƴ� 
		if(dist[here]<cost) { //�̰ͺ��� �̹� �ּҷ� ������ ����̸� 
			continue; //�н� 
		}
		for(int i=0; i<graph[here].size(); i++) { //������ ��� ���鿡 ���� 
			int there=graph[here][i].first; //���� ��� 
			int ncost=cost + graph[here][i].second; //������� �ּҺ�뿡 �߰������ ���� ���� 
			if(ncost<dist[there]) { //���� ����� ������ ������ 
				dist[there]=ncost; //�����ϰ� 
				pq.push(make_pair(-ncost, there)); //pq�� ���� 
			}
		}
	}
}
