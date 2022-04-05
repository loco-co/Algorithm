#include <iostream>
#include <vector>
using namespace std;
int n,m,roadcnt,ans;
int town[100001]; //크루스칼 
vector<pair<int,int>> cost[1001]; //비용순으로 엣지들을 정렬하기 위해 벡터 사용 
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
		cin>>a>>b>>c; //priority queue 사용 실패, 정렬할 필요 없음 
		cost[c].push_back({a,b});
	}
	for(int i=1; i<=1000; i++) { //비용은 1부터 1000까지 
		for(int j=0; j<cost[i].size(); j++) {
			a=cost[i][j].first;
			b=cost[i][j].second;
			if(find(a)!=find(b)) { //두 도시의 마을 집합이 다르면 
				Union(a,b); roadcnt++; ans += i; //마을이 2개가 될 때까지 합침 
			}
			if(roadcnt==n-2) { //마을 2개의 mst를 구하기 위해서는 
				cout<<ans; //마을-2 만큼 엣지만 뽑으면 됨  
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
