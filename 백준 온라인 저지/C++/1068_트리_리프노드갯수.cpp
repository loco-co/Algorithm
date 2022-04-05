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
	leafcnt=n; //������ ó�� n���̴ٰ� �θ�� �ҷ����� ���� 
	for(int i=0; i<n; i++) {
		leaf[i]=true;
	}
	for(int i=0; i<n; i++) {
		cin>>p;
		parent[i]=p;
		if(p==-1) { //��Ʈ ����̸� 
			tree[i].push_back(-1); //0���� ��Ʈ���� �����ߴٰ� Ʋ�� 
			continue; //���� ���� �н� 
		}
		if(leaf[p]) { //leaf[-1]�� ���� �ȵǾ��־ Ʋ�� 
			leaf[p]=false;
			leafcnt--;
		}
		tree[p].push_back(i);
		tree[i].push_back(p);
	}
	int remove; cin>>remove;
	dfs(remove);
	int k=parent[remove]; //�����ϴ� ����� �θ��尡 
	if(k!=-1 && tree[k].size()==2) { //�ڽ��� 1���ۿ� �������� 
		leafcnt++;
	} //k��-1�̸� �����ϴ� ��尡 ��Ʈ����� ��� 
	cout<<leafcnt;
	return 0;
}
void dfs(int a) {
	if(tree[a].size()==1) { //a�� ��������̸� 
		leafcnt--;
		return;
	}
	for(int i=0; i<tree[a].size(); i++) {
		int node=tree[a][i]; //����� ��� ���鿡 ���� 
		if(node==parent[a]) { continue; } //�θ� ����̸� �н��ϰ� 
		dfs(node); //�Ʒ��� Ž�� 
	}
}
