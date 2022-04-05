#include <iostream>
using namespace std;
int main(void) {
    //cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
    int t=0;
    while(true) {
        int p,camp,holiday;
        cin>>camp>>p>>holiday;
        if(p==0) { break; } //p가 0이면 탈출
        int q=holiday/p*camp;
        int r=holiday%p; t++; //r은 최대로 채우고 남은날짜
        if(r<=camp) {
            q += r;
        }
        else { q += camp; } //r이 camp날짜보다 크면
        cout<<"Case "<< t <<": "<< q <<'\n';
    }
    return 0;
}