#include <iostream>
#include <algorithm> //sort
using namespace std;
int main(void) {
    //cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
    int n=9; int dwarf[9];
    int sum=0;
    for(int i=0; i<9; i++) {
        cin>>dwarf[i];
        sum += dwarf[i];
    }
    sort(dwarf, dwarf+9); //중요 sort(시작 it, 마지막 it)
    int diff=sum-100; int not1,not2; //100에서만큼 차이나는 값 diff
    for(int i=0; i<9; i++) {
        for(int j=i+1; j<9; j++) {
            if(dwarf[i]+dwarf[j]==diff) { //두 난쟁이의 키의 합이 diff와 같다면
                not1=i; not2=j; //2명을 빼야함
            }
        }
    }
    for(int i=0; i<9; i++) {
        if(i==not1 || i==not2) { continue; } //2명빼고 오름차순으로 출력
        cout<<dwarf[i]<<'\n';
    }
    return 0;
}