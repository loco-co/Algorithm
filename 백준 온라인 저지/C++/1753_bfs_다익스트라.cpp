#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define max 20000
#define infinite 3000000
using namespace std;
int v,e,k;
struct edge {
	int j;
	int weight;
};
vector<edge> graph[max]; //bfs()�� Ǯ�� �ȵ�, ���ͽ�Ʈ�� != bfs, edge ����ü�� �����ϴ� ������ �迭�� ���� 
int cost[max][max]; //�޸� �ʰ� 
queue<int> q; //������ ���� ������ ���� ť 
void bfs();
bool visit[max];
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	cin>>v>>e>>k;
	int i,j,w;
	for(int n=0; n<e; n++) {
		cin>>i>>j>>w;
		graph[i].push_back({j,w});
	}
	for(int a=0; a<max; a++) {
		for(int b=0; b<max; b++) {
			cost[a][b]=infinite;
		}
	}
	//memset(cost, 99999, sizeof(cost)); ���� 
	cost[k][k]=0;
	q.push(k); visit[k]=1;
	bfs();
	for(int n=1; n<=v; n++) { //�ε��� �Ǽ� 
		if(cost[k][n]==infinite) {
			cout<<"INF"<<'\n';
		}
		else cout<<cost[k][n]<<'\n';
	}
	return 0;
}
void bfs() {
	while(!q.empty()) {
		int i=q.front(); q.pop();
		for(int n=0; n<graph[i].size(); n++) {
			int j=graph[i][n].j;
			int weight=graph[i][n].weight;
			if(i==k) { //���� �������κ����� �����̸� 
				cost[k][j]=weight; //�ٷ� �� ���� 
			}
			else {
				//cout<<'c'<<cost[k][i];
				cost[k][j]=min(cost[k][j], cost[k][i]+weight);// k���� j�� ���� ������ ��뺸�� 
				//cout<<'c'<<cost[k][j];  //k���� i�� ���ļ� j�� ���°� �θ� ����
			}
			if(!visit[j]) {
				q.push(j); visit[j]=1;
			}
		}
	}
} 
