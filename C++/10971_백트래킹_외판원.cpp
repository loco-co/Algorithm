#include <iostream>
using namespace std;
int n;
int W[10][10];
int mincost=1e9;
bool visit[10];
void travel(int, int, int);
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin>>W[i][j];
		}
	}
	visit[0]=true;
	travel(1,0,0); //맨 처음 시작 도시는 0번으로 해도 무관함 
	cout<<mincost;
	return 0;
}
void travel(int k, int i, int cost) { //i는 출발하는 도시 
	if(k==n) {
		if(W[i][0]) { //시작 도시로 돌아오는 길이 있으면 
			cost += W[i][0];
			if(cost<mincost) { mincost=cost; }
		}
		return;
	}
	for(int j=0; j<n; j++) {
		if(W[i][j]>0 && !visit[j]) { //길이 있고, 방문한 적 없으면 
			cost += W[i][j]; visit[j]=true; //값을 더하고 방문표시 
			travel(k+1, j, cost);
			cost -= W[i][j]; visit[j]=false;
		}
	}
}
