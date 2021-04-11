#include <iostream>
#include <queue>
using namespace std;
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int n,a; cin>>n;
	queue<int> q;
	for(int i=1; i<=n; i++) {
		q.push(i);
	}
	while(q.size()>1) {
		q.pop();
		a=q.front(); q.pop();
		q.push(a);
	}
	cout<<q.back();
	return 0;
}
