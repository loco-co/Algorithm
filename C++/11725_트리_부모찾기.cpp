#include <iostream>
#include <queue>
#define max 100000
using namespace std;
vector<int> tree[max+1]; //Ʈ���� �׷����� Ư���� ���. 
queue<int> q;
int parent[max+1]; //����� �θ� ���� 
void bfs();
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int n; cin>>n;
	int k,j;
	for(int i=0; i<n-1; i++) {
		cin>>k>>j;
		tree[k].push_back(j);
		tree[j].push_back(k);
	}
	q.push(1);
	bfs();
	for(int i=2; i<=n; i++) {
		cout<<parent[i]<<'\n';
	}
	return 0;
}
void bfs() {
	while(!q.empty()) {
		int p=q.front(); q.pop(); //q���� 1�� ������ 
		for(int i=0; i<tree[p].size(); i++) {
			int child=tree[p][i]; //����� ��� ���鿡 ���� 
			if(child==parent[p]) { continue; } //�װ� �θ�� �н��ϰ� 
			parent[child]=p; //�ڽ��̸� �θ� ��� 
			q.push(child); //�ڽĵ�� ���̿켱Ž�� 
		}
	}
}
