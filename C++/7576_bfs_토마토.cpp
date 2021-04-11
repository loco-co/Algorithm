#include <iostream>
#include <queue>
using namespace std;
void bfs();
bool boundary(int, int);
struct point {
	int x;
	int y;
};
int m,n;
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, -1, 0, 1};
int tomato[1001][1001];
queue<point> q;
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	cin>>m>>n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>tomato[i][j];
			if(tomato[i][j]==1) { //1은 1일차에 익은것 
				q.push({i,j});
			}
		}
	}
	bfs();
	int day=1;
	for(int i=0; i<n; i++) { //토마토를 하나씩 체크 
		for(int j=0; j<m; j++) {
			if(tomato[i][j]==0) {
				cout<<-1;
				return 0;
			}
			if(tomato[i][j]>day) {
				day=tomato[i][j];
			}
		}
	}
	cout<<day-1<<'\n';
	return 0; 
}

void bfs() {
	while(!q.empty()) { //큐가 빌때까지 bfs
		point tmt;
		tmt.x=q.front().x;
		tmt.y=q.front().y; q.pop();
		for(int i=0; i<4; i++) {
			int nx=tmt.x+dx[i];
			int ny=tmt.y+dy[i];
			if(boundary(nx, ny) && tomato[nx][ny]==0) { //창고 안에서 인접한 토마토가 안 익었으면 
				q.push({nx, ny});
				tomato[nx][ny]=tomato[tmt.x][tmt.y]+1; //날짜 값을 배열의 숫자로 나타냄 
			}
		}
	}
}

bool boundary(int a, int b) {
	return (0 <= a && 0 <= b && a < n && b < m); //경계값 주의 
}
