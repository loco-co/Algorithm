#include <iostream>
using namespace std;
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int n; cin>>n;
	int ans; int count=0; string tmp;
	for(int i=666; count!=n; i++){
		tmp=to_string(i);
		if(tmp.find("666") != string::npos) { //666을 포함하면 
			count++;
			ans=i;
		}
	}
	cout<<ans;
	return 0;
}
