#include <iostream>
#include <queue>
using namespace std;
int graph[100][100];
struct edge {
	int i;
	int j;
};
queue<edge> q;
void bfs(); int n;
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin>>graph[i][j];
			if(graph[i][j]==1) {
				q.push({i, j});
			}
		}
	} //인접 그래프 
	bfs();
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout<<graph[i][j]<<" ";
		}
		cout<<'\n';
	}
	return 0;
}
void bfs() {
	while(!q.empty()) {
		int i=q.front().i;
		int j=q.front().j; q.pop();
		for(int k=0; k<n; k++) { //j열만 보면됨 
			if(graph[j][k]==1 && graph[i][k]==0) { //j에서 k로 엣지가 있고, i에서 k로 가는 경로가 추가된 적 없으면 
				q.push({i, k}); //추가된 엣지로 부터 다시 bfs() 
				graph[i][k]=1; //i에서 j, j에서 k로 갈 수 있으면 i에서 k로 경로가 존재함 
			}
		}
	}
}
