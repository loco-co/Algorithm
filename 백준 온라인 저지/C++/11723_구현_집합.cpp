#include <iostream>
#include <string>
using namespace std;
bool Set[21]; //������ ǥ�� 
void add(int);
void remove(int);
void check(int);
void toggle(int);
void all();
void empty();
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int t,x; cin>>t;
	for(int i=0; i<t; i++) {
		string s; cin>>s;
		if(s=="add") { cin>>x; add(x); }
		if(s=="remove") { cin>>x; remove(x); }
		if(s=="check") { cin>>x; check(x); }
		if(s=="toggle") { cin>>x; toggle(x); }
		if(s=="all") { all(); }
		if(s=="empty") { empty(); }
	}
	return 0;
}
void add(int x) {
	Set[x]=1;
}
void remove(int x) {
	Set[x]=0;
}
void check(int x) {
	if(Set[x]) { cout<<1<<'\n'; }
	else { cout<<0<<'\n'; } //���๮�� �ʿ��� 
}
void toggle(int x) {
	if(Set[x]) { Set[x]=0; }
	else { Set[x]=1; }
}
void all() {
	for(int i=1; i<21; i++)
		Set[i]=1;
}
void empty() {
	for(int i=1; i<21; i++)
		Set[i]=0;
}
