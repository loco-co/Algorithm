#include <iostream>
using namespace std;
struct call{
	int zero,one;
};
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int T; cin>>T;
	call Fibbo[41];
	Fibbo[0].zero=1; Fibbo[0].one=0;
	Fibbo[1].zero=0; Fibbo[1].one=1;
	for(int i=2; i<41; i++) {
		Fibbo[i].zero=Fibbo[i-2].zero + Fibbo[i-1].zero;
		Fibbo[i].one=Fibbo[i-2].one + Fibbo[i-1].one;
	}
	int test;
	for(int j=0; j<T; j++) {
		cin>>test;
		cout<<Fibbo[test].zero<<' '<<Fibbo[test].one<<'\n';
	}
	return 0;
}
