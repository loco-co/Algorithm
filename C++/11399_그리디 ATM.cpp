#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int, int);
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int n; cin>>n;
	int p[n];
	for(int i=0; i<n; i++) {
		cin>>p[i];
	}
	sort(p, p+n, cmp); //shortest time first
	int weight=0; int sum=0; //°¡ÁßÄ¡ weight
	for(int i=0; i<n; i++) {
		sum += p[i] + weight;
		weight += p[i];
	}
	cout<<sum;
	return 0;
}
bool cmp(int a, int b) {
	if(a < b)
		return 1;
	else
		return 0;
}
