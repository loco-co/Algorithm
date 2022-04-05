#include <iostream>
#include <queue>
#define max 101
using namespace std;
int n, m;
int maze[max][max];
struct point {
	int x, y;
};
queue<point> q;
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, -1, 0, 1};
void bfs();
bool boundary(int, int);
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	cin>>n>>m;
	string line; //연속된 숫자열 
	for(int i=0; i<n; i++) {
		cin>>line;
		for(int j=0; j<m; j++) {
			maze[i][j]=int(line[j]-'0'); //string의 원소 1개씩 '0'을 빼서 미로에 저장 
		}
	}
	q.push({0,0});
	bfs();
	cout<<maze[n-1][m-1]; //도착 지점 
	return 0;
}

void bfs() {
	while(!q.empty()) {
		int x=q.front().x;
		int y=q.front().y; q.pop();
		int nx, ny;
		for(int i=0; i<4; i++) {
			nx=x+dx[i];
			ny=y+dy[i];
			if(boundary(nx, ny) && maze[nx][ny]==1) { //1은 갈 수 있고 간 적 없다는 뜻 
				maze[nx][ny]=maze[x][y]+1; //도달하는데까지 걸린 거리를 미로에 저장 
				q.push({nx, ny});
			}
		}
	}
	return;
}

bool boundary(int x, int y) {
	return ( 0 <= x && 0 <=y && x < n && y < m);
}
