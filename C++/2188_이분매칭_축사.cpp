#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int n,m,cnt;
vector<int> graph[201];
int cs[201]; //��� 
bool visit[201];
bool dfs(int);
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		int t,s; cin>>t;
		for(int j=0; j<t; j++) {
			cin>>s;
			graph[i].push_back(s);
		}
	}	
	for(int i=1; i<=n; i++) { //1�� �Һ��� n�� �ұ��� 
		bool temp=dfs(i);
		memset(visit, 0, sizeof(visit));
	}
	cout<<cnt;
	return 0;
}
bool dfs(int i) {
	visit[i]=1;
	for(int k=0; k<graph[i].size(); k++) {
		int t=graph[i][k]; //cs[t]�� �� 
		if(visit[cs[t]]) { continue; } //�湮�� �� ������ ��ŵ 
		
		if(cs[t]==0) { //�Ұ� �����Ǿ� ���� ���� ��縦 ã���� 
			cs[t]=i; cnt++; return true; //���� ��θ� ã�� (������ 1����) 
		}
		else if(dfs(cs[t])) { //�Ұ� �����Ǿ� ������, �� �Ұ� �ٸ��� ������ �� �ִ��� Ž���ϰ� 
			cs[t]=i; return true; //�� �Ұ� �ٸ��� �����Ǹ� �� �Ҹ� �ű�� �ٲ� 
		}
	}
	return false; //�� �õ��ص� �ȵǸ� ���� 
}
//else { if(cs[t]==i) { continue; } }
