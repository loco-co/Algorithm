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
	} //���� �׷��� 
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
		for(int k=0; k<n; k++) { //j���� ����� 
			if(graph[j][k]==1 && graph[i][k]==0) { //j���� k�� ������ �ְ�, i���� k�� ���� ��ΰ� �߰��� �� ������ 
				q.push({i, k}); //�߰��� ������ ���� �ٽ� bfs() 
				graph[i][k]=1; //i���� j, j���� k�� �� �� ������ i���� k�� ��ΰ� ������ 
			}
		}
	}
}
