#include <iostream>
#include <queue>
#define size 50
using namespace std;
int n,m,k;
int cabbage[size][size];
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, -1, 0, 1};
struct point {
	int x,y;
};
queue<point> q;
void bfs();
bool boundary(int, int);
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int test; cin>>test;
	for(int t=0; t<test; t++) {
		cin>>m>>n>>k;
		int x,y; int worm=0;
		for(int i=0; i<k; i++) {
			cin>>y>>x; cabbage[x][y]=1; //배추 심기 
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(cabbage[i][j]==1) {
					q.push({i,j}); worm++; cabbage[i][j]=2;
					bfs(); //bfs()호출한 영역 하나당 한 마리, bfs()하고 난 배추는 2로 변경 
				}
				else { continue; }
			}
		}
		cout<<worm<<'\n';
	}
	return 0;
}
void bfs() {
	while(!q.empty()) {
		int x=q.front().x;
		int y=q.front().y; q.pop();
		for(int i=0; i<4; i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(boundary(nx ,ny) && cabbage[nx][ny]==1) { //배추밭 경계 내에 있고, 배추가 심겨 있는데 bfs()된 적 없으면 
				cabbage[nx][ny]=2; q.push({nx, ny}); //그 배추는 2로 변경하고 bfs()로 계속 탐색 
			}
		}
	}
}
bool boundary(int x, int y) {
	return (0 <= x && 0 <= y && x < n && y < m);
}
