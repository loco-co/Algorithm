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
			if(tomato[i][j]==1) { //1�� 1������ ������ 
				q.push({i,j});
			}
		}
	}
	bfs();
	int day=1;
	for(int i=0; i<n; i++) { //�丶�並 �ϳ��� üũ 
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
	while(!q.empty()) { //ť�� �������� bfs
		point tmt;
		tmt.x=q.front().x;
		tmt.y=q.front().y; q.pop();
		for(int i=0; i<4; i++) {
			int nx=tmt.x+dx[i];
			int ny=tmt.y+dy[i];
			if(boundary(nx, ny) && tomato[nx][ny]==0) { //â�� �ȿ��� ������ �丶�䰡 �� �;����� 
				q.push({nx, ny});
				tomato[nx][ny]=tomato[tmt.x][tmt.y]+1; //��¥ ���� �迭�� ���ڷ� ��Ÿ�� 
			}
		}
	}
}

bool boundary(int a, int b) {
	return (0 <= a && 0 <= b && a < n && b < m); //��谪 ���� 
}
