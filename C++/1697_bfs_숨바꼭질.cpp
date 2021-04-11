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
	q.push(n); space[n]=1; //n���� bfs�ؼ� key�� �ּҷ� ã�´� 
	bfs();
	if(n==key) cout<<0;
	else cout<<space[key]-1;
	return 0;
}
void bfs() {
	while(!q.empty()) {
		int place=q.front(); q.pop();
		int p[3]; //�� �� �ִ� 3���� ��� 
		p[0]=place*2;
		p[1]=place+1;
		p[2]=place-1;
		for(int i=0; i<3; i++) {
			if(p[i]==key) { //�������� ã���� 
				space[p[i]]=space[place]+1;
				return; //����Ż���ϰ� �ٷ� ���� 
			}
			if(bound(p[i]) && space[p[i]]==0) { //�湮�� �� ������ 
				q.push(p[i]); space[p[i]]=space[place]+1; //������� �ɸ� �ּ� �ð��� space�� ���� 
			}
		}
	}
}
bool bound(int a) {
	return ( a >= 0 && a <= 100000);
}
