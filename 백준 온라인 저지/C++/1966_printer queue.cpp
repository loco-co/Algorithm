#include <iostream>
#include <queue>
using namespace std;
struct node {
	int val; //�߿䵵 �� 
	int position; //��ġ�� ��Ÿ���� ���� 
};
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int n; cin>>n;
	for(int i=0; i<n; i++) { //�׽�Ʈ ���̽���ŭ ��ü ���� 
		int count, key, a;
		int ans=0;
		queue<node> q;
		int array[10]={}; //�ε����� �߿䵵�� ���� ������ ������ ���� 
		cin>>count>>key;
		for(int j=0; j<count; j++) {
			cin>>a; array[a]++;
			q.push({a,j});
		}
		for(int k=9; k>=1; k--) { //���� �߿䵵���� 
			while(array[k]!=0) { //������ ��� 
				int v=q.front().val;
				int p=q.front().position;
				q.pop();
				if(v==k) { //���Ұ� ���� �߿䵵�� �����̸� 
					 ans++; array[k]--;
					 if(p==key) { //�츮�� ���ϴ� �� ���Ҹ� 
				 		cout<<ans<<'\n'; //��� Ƚ�� 
					 }
				}
				else { //������ ������ 
					q.push({v,p}); //�ٽ� �ڷ� 
				}
			}
		}
	}
	return 0;
}
