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
	string line; //���ӵ� ���ڿ� 
	for(int i=0; i<n; i++) {
		cin>>line;
		for(int j=0; j<m; j++) {
			maze[i][j]=int(line[j]-'0'); //string�� ���� 1���� '0'�� ���� �̷ο� ���� 
		}
	}
	q.push({0,0});
	bfs();
	cout<<maze[n-1][m-1]; //���� ���� 
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
			if(boundary(nx, ny) && maze[nx][ny]==1) { //1�� �� �� �ְ� �� �� ���ٴ� �� 
				maze[nx][ny]=maze[x][y]+1; //�����ϴµ����� �ɸ� �Ÿ��� �̷ο� ���� 
				q.push({nx, ny});
			}
		}
	}
	return;
}

bool boundary(int x, int y) {
	return ( 0 <= x && 0 <=y && x < n && y < m);
}
