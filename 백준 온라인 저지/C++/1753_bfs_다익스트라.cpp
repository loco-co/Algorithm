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
vector<edge> graph[max]; //bfs()로 풀면 안됨, 다익스트라 != bfs, edge 구조체를 저장하는 벡터의 배열을 생성 
int cost[max][max]; //메모리 초과 
queue<int> q; //엣지의 시작 지점을 넣을 큐 
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
	//memset(cost, 99999, sizeof(cost)); 오류 
	cost[k][k]=0;
	q.push(k); visit[k]=1;
	bfs();
	for(int n=1; n<=v; n++) { //인덱스 실수 
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
			if(i==k) { //시작 지점으로부터의 엣지이면 
				cost[k][j]=weight; //바로 값 저장 
			}
			else {
				//cout<<'c'<<cost[k][i];
				cost[k][j]=min(cost[k][j], cost[k][i]+weight);// k에서 j로 가는 기존의 비용보다 
				//cout<<'c'<<cost[k][j];  //k에서 i를 거쳐서 j로 가는게 싸면 갱신
			}
			if(!visit[j]) {
				q.push(j); visit[j]=1;
			}
		}
	}
} 
