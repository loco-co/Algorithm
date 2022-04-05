#include <iostream>
#include <queue>
using namespace std;
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int n,k; cin>>n>>k;
	queue<int> q;
	for(int i=1; i<=n; i++) {
		q.push(i);
	}
	cout<<'<';
	while(q.size()>1) {
		for(int i=0; i<k-1; i++) { //k-1까지는 빼서 뒤에 넣고 
			int t=q.front(); q.pop();
			q.push(t);
		}
		int a=q.front(); q.pop(); //k번째는 빼서 
		cout<<a<<", "; //출력한다 
	}
	cout<<q.front()<<'>';
	return 0;
} //disk interleaving
