#include <iostream>
#include <vector>
using namespace std;
vector<int> tree[51];
int parent[51];
bool leaf[51];
int leafcnt;
void dfs(int);
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int n,p; cin>>n;
	leafcnt=n; //리프는 처음 n개이다가 부모로 불려지면 감소 
	for(int i=0; i<n; i++) {
		leaf[i]=true;
	}
	for(int i=0; i<n; i++) {
		cin>>p;
		parent[i]=p;
		if(p==-1) { //루트 노드이면 
			tree[i].push_back(-1); //0번을 루트노드로 고정했다가 틀림 
			continue; //뒤의 과정 패스 
		}
		if(leaf[p]) { //leaf[-1]이 정의 안되어있어서 틀림 
			leaf[p]=false;
			leafcnt--;
		}
		tree[p].push_back(i);
		tree[i].push_back(p);
	}
	int remove; cin>>remove;
	dfs(remove);
	int k=parent[remove]; //제거하는 노드의 부모노드가 
	if(k!=-1 && tree[k].size()==2) { //자식이 1개밖에 없었으면 
		leafcnt++;
	} //k가-1이면 제거하는 노드가 루트노드인 경우 
	cout<<leafcnt;
	return 0;
}
void dfs(int a) {
	if(tree[a].size()==1) { //a가 리프노드이면 
		leafcnt--;
		return;
	}
	for(int i=0; i<tree[a].size(); i++) {
		int node=tree[a][i]; //연결된 모든 노드들에 대해 
		if(node==parent[a]) { continue; } //부모 노드이면 패스하고 
		dfs(node); //아래로 탐색 
	}
}
