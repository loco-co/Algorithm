#include <iostream>
#include <queue>
#define max 100000
using namespace std;
vector<pair<int,int>> tree[max+1];
int dist[max+1];
queue<int> q;
int ans,v1;
bool visit[max+1];
void bfs();
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int n,v,j,w; cin>>n;
	for(int i=0; i<n; i++) {
		cin>>v;
		while(1) {
			cin>>j;
			if(j==-1) { break; }
			cin>>w;
			tree[v].push_back({j,w});
		}
	}
	q.push(1); visit[1]=true;
	bfs();
	for(int j=1; j<=n; j++) { //fill()�� ��ü ���� 
		dist[j]=0;
		visit[j]=false;
	}
	q.push(v1); visit[v1]=true;
	bfs();
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
				v1=node; //���� �� �Ÿ��� �ִ� ��嵵 ���� 
			}
			q.push(node);
		}
	}
}
//"�ƹ� ��(v)���� �����ؼ� ���� �� ��(v1)�� ã��, 
//�� ��(v1)���� ���� �� ��(v2)�� ã����, 
//v1�� v2 ������ �Ÿ��� Ʈ���� �����̵˴ϴ�."
