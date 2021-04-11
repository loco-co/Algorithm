#include <iostream>
#include <queue>
using namespace std; 
int n,key;
int space[100001];
queue<int> q;
void bfs();
bool bound(int);
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	cin>>n>>key;
	q.push(n); space[n]=1; //n부터 bfs해서 key를 최소로 찾는다 
	bfs();
	if(n==key) cout<<0;
	else cout<<space[key]-1;
	return 0;
}
void bfs() {
	while(!q.empty()) {
		int place=q.front(); q.pop();
		int p[3]; //갈 수 있는 3가지 경우 
		p[0]=place*2;
		p[1]=place+1;
		p[2]=place-1;
		for(int i=0; i<3; i++) {
			if(p[i]==key) { //목적값을 찾으면 
				space[p[i]]=space[place]+1;
				return; //루프탈출하고 바로 리턴 
			}
			if(bound(p[i]) && space[p[i]]==0) { //방문한 적 없으면 
				q.push(p[i]); space[p[i]]=space[place]+1; //오기까지 걸린 최소 시간을 space에 저장 
			}
		}
	}
}
bool bound(int a) {
	return ( a >= 0 && a <= 100000);
}
