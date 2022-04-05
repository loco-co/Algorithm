#include <iostream>
using namespace std;
int l,c;
char arr[16];
char ans[16];
void travel(int, int, int);
int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	cin>>l>>c;
	for(int i=0; i<c; i++) {
		cin>>arr[i];
	}
	for(int i=0; i<c; i++) { //간단하게 정렬 
		for(int j=0; j<c-1; j++) {
			if(arr[j]>arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
		}
	}
	travel(1,0,0);
	return 0;
}
void travel(int n, int mo, int ja) {
	if(n==l+1) { //종료조건 
		if(mo>=1 && ja>=2) { //모두 탐색후 조건에 맞을때만 출력 
			for(int i=1; i<=l; i++) { //모두 탐색하지 않으면 조건이 더러워짐 
				cout<<ans[i];
			}
			cout<<'\n';
		}
		return;
	}
	for(int i=0; i<c; i++) {
		if(arr[i]>ans[n-1]) { //유망하면, 이전 저장 문자보다 후보 문자들 중 큰 문자들만 탐색 
			ans[n]=arr[i];
			if(ans[n]=='a' || ans[n]=='e' || ans[n]=='i' || ans[n]=='o' || ans[n]=='u') {
				mo++; //모음 갯수 증가 
			}
			else { ja++; }
			
			travel(n+1, mo, ja);
			
			if(ans[n]=='a' || ans[n]=='e' || ans[n]=='i' || ans[n]=='o' || ans[n]=='u') {
				mo--; //탈출 후 모음 갯수 원래대로 
			}
			else { ja--; }
		}
	}
}
