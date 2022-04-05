#include <iostream>
using namespace std;
int main(void) {
	long u,d,v; long h=0;
	long count=0;
	cin>>u>>d>>v;
	while(1) {
		count++;
		h += u;
		if(h>=v) {
			cout<<count;
			return 0;
		}
		h -= d;
	}
}
