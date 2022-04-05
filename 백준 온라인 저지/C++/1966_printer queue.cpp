#include <iostream>
#include <queue>
using namespace std;
struct node {
	int val; //중요도 값 
	int position; //위치를 나타내는 변수 
};
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int n; cin>>n;
	for(int i=0; i<n; i++) { //테스트 케이스만큼 전체 루프 
		int count, key, a;
		int ans=0;
		queue<node> q;
		int array[10]={}; //인덱스의 중요도를 가진 원소의 갯수를 저장 
		cin>>count>>key;
		for(int j=0; j<count; j++) {
			cin>>a; array[a]++;
			q.push({a,j});
		}
		for(int k=9; k>=1; k--) { //높은 중요도부터 
			while(array[k]!=0) { //끝까지 출력 
				int v=q.front().val;
				int p=q.front().position;
				q.pop();
				if(v==k) { //원소가 지금 중요도의 레벨이면 
					 ans++; array[k]--;
					 if(p==key) { //우리가 원하는 그 원소면 
				 		cout<<ans<<'\n'; //출력 횟수 
					 }
				}
				else { //레벨이 낮으면 
					q.push({v,p}); //다시 뒤로 
				}
			}
		}
	}
	return 0;
}
