#include <iostream>
#include <queue>
#define max 10000
using namespace std;
vector<pair<int,int>> tree[max+1];
int dist[max+1];
queue<int> q;
int ans;
bool visit[max+1];
void bfs();
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int n,k,j,w; cin>>n;
	for(int i=0; i<n-1; i++) {
		cin>>k>>j>>w;
		tree[k].push_back({j,w});
		tree[j].push_back({k,w}); //Ʈ���� ����� �׷��� 
	}
	for(int i=1; i<=n; i++) { //1�� ������ n�� ������ bfs 
		q.push(i); visit[i]=true;
		bfs();
		for(int j=1; j<=n; j++) {
			dist[j]=0;
			visit[j]=false;
		}
	}
	cout<<ans;
	return 0;
}
void bfs() {
	while(!q.empty()) {
		int p=q.front(); q.pop();
		for(int i=0; i<tree[p].size(); i++) {
			int node=tree[p][i].first;
			int cost=tree[p][i].second; //����� ��� ���鿡 ���� 
			if(visit[node]) { continue; } //�湮�� �� �ִ� ���� �н� 
			visit[node]=true;
			dist[node]=dist[p]+cost; //���� node���� �Ÿ��� �� ������ �Ÿ� + ��� ��� 
			if(ans<dist[node]) { //�� ���� ���� �ִ񰪺��� ũ�� ���� 
				ans=dist[node];
			}
			q.push(node);
		}
	}
}
