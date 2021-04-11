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
	travel(1,0,0); //�� ó�� ���� ���ô� 0������ �ص� ������ 
	cout<<mincost;
	return 0;
}
void travel(int k, int i, int cost) { //i�� ����ϴ� ���� 
	if(k==n) {
		if(W[i][0]) { //���� ���÷� ���ƿ��� ���� ������ 
			cost += W[i][0];
			if(cost<mincost) { mincost=cost; }
		}
		return;
	}
	for(int j=0; j<n; j++) {
		if(W[i][j]>0 && !visit[j]) { //���� �ְ�, �湮�� �� ������ 
			cost += W[i][j]; visit[j]=true; //���� ���ϰ� �湮ǥ�� 
			travel(k+1, j, cost);
			cost -= W[i][j]; visit[j]=false;
		}
	}
}
