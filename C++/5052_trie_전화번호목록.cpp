#include <iostream>
#include <string>
using namespace std;
bool flag=1; //끝난 노드를 지났는지 여부, 일관성이 있으면 1 
struct Trie {
	Trie* child[11];
	bool fin=0;

	Trie() {
		for(int i=0; i<11; i++) {
			child[i]=NULL;
		}
	}

	~Trie() { //소멸자 
		for(int i=0; i<10; i++) {
			if(child[i]) {
				delete child[i];
			}
		}
	}

	bool insert(int i, string word) { //일관성 있으면 1 리턴 
		if(i==word.size()) { //문자열의 끝인 널을 만났으면 
			fin=1; //해당 노드는 끝난 전화번호이고 
			for(int j=0; j<11; j++) {
				if(!flag || child[j]!=NULL) { //중간에 끝난 노드를 만났거나 
					flag=true; // 자식중에 할당된 노드가 1개라도 있으면 
					return false; //flag 초기화하고 일관성 없음 리턴 
				}
			}
			return true; //다 통과하면 일관성 있음 
		}
		int pos=word[i]-'0'; //0~10까지 할당하기 위해 
		if(child[pos]==NULL) { //할당된게 없으면 
			child[pos]=new Trie(); //trie를 생성하고 할당 
		}
		if(fin==1) { flag=false; } //이 노드에 fin표시가 되있으면 flag=false 
		return insert(i+1, word); //다음 인덱스 문자 삽입 
	}

	bool find(int i, string word) { //문자열이 있는지 탐색 
		if(i==word.size()) {
			if(fin==1) return true;
			else return false;
		}
		int pos=word[i]-'0';
		if(child[pos]==NULL) { return false; } //중간에 할당된게 없는걸 찾으면 즉시 실패 리턴 
		
		return child[pos]->find(i+1, word); //다음 인덱스 문자 탐색 
	}
};
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--) {
		Trie *trie=new Trie(); //테스트케이스마다 생성 
		int n; cin>>n;
		bool ans=true;
		for(int i=0; i<n; i++) {
			string s; cin>>s;
			if(trie->insert(0,s)) {
				continue;
			}
			else { ans=false; } //1번이라도 일관성없으면 no 
		}
		if(ans) {
			cout<<"YES"<<'\n';
		}
		else cout<<"NO"<<'\n';
		delete trie; //삭제 
	}
	return 0;
}
