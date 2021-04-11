#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int n,m,cnt;
vector<int> graph[201];
int cs[201]; //축사 
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
	for(int i=1; i<=n; i++) { //1번 소부터 n번 소까지 
		bool temp=dfs(i);
		memset(visit, 0, sizeof(visit));
	}
	cout<<cnt;
	return 0;
}
bool dfs(int i) {
	visit[i]=1;
	for(int k=0; k<graph[i].size(); k++) {
		int t=graph[i][k]; //cs[t]는 소 
		if(visit[cs[t]]) { continue; } //방문한 적 있으면 스킵 
		
		if(cs[t]==0) { //소가 배정되어 있지 않은 축사를 찾으면 
			cs[t]=i; cnt++; return true; //증가 경로를 찾음 (무조건 1증가) 
		}
		else if(dfs(cs[t])) { //소가 배정되어 있으면, 그 소가 다른데 배정될 수 있는지 탐색하고 
			cs[t]=i; return true; //그 소가 다른데 배정되면 이 소를 거기로 바꿈 
		}
	}
	return false; //다 시도해도 안되면 실패 
}
//else { if(cs[t]==i) { continue; } }
