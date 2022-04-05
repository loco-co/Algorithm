#include <iostream>
#include <vector>
using namespace std;
int n,m,roadcnt,ans;
int town[100001]; //ũ�罺Į 
vector<pair<int,int>> cost[1001]; //�������� �������� �����ϱ� ���� ���� ��� 
int find(int);
void Union(int, int);
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1; i<=100000; i++) {
		town[i]=i;
	}
	int a,b,c;
	for(int i=0; i<m; i++) {
		cin>>a>>b>>c; //priority queue ��� ����, ������ �ʿ� ���� 
		cost[c].push_back({a,b});
	}
	for(int i=1; i<=1000; i++) { //����� 1���� 1000���� 
		for(int j=0; j<cost[i].size(); j++) {
			a=cost[i][j].first;
			b=cost[i][j].second;
			if(find(a)!=find(b)) { //�� ������ ���� ������ �ٸ��� 
				Union(a,b); roadcnt++; ans += i; //������ 2���� �� ������ ��ħ 
			}
			if(roadcnt==n-2) { //���� 2���� mst�� ���ϱ� ���ؼ��� 
				cout<<ans; //����-2 ��ŭ ������ ������ ��  
				return 0;
			}
		}
	}
}
int find(int a) {
	if(a==town[a]) return a;
	else { return town[a]=find(town[a]); }
}
void Union(int a, int b) {
	int roota=find(a);
	int rootb=find(b);
	if(roota==rootb) return;
	else {
		town[rootb]=roota;
		return;
	}
}
