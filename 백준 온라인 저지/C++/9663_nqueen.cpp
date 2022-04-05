#include <iostream>
using namespace std;
void nqueen(int, int);
int count=0;
int col[15],row[15];
int promising(int i, int j);
int main(void) {
	int N; cin>>N;
	nqueen(N, N);
	cout<<count;
	return 0;
}
void nqueen(int n, int q) {
	if(q==n) {
		count++;
		return;
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(promising(i, j)) {
				row[i]=i;
				col[j]=j;
				nqueen(n, q+1); 
			}
		}
	}
}
int promising(int i, int j) {
	if(row[i]==i)
		return false;
	else if(col[j]==j)
		return false;
	else if((row[i]-col[j]) == i-j)
		return false;
	else if((col[j]-row[i]) == i-j)
		return false;
	else
		return true;
}
