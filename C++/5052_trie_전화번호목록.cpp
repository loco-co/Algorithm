#include <iostream>
#include <string>
using namespace std;
bool flag=1; //���� ��带 �������� ����, �ϰ����� ������ 1 
struct Trie {
	Trie* child[11];
	bool fin=0;

	Trie() {
		for(int i=0; i<11; i++) {
			child[i]=NULL;
		}
	}

	~Trie() { //�Ҹ��� 
		for(int i=0; i<10; i++) {
			if(child[i]) {
				delete child[i];
			}
		}
	}

	bool insert(int i, string word) { //�ϰ��� ������ 1 ���� 
		if(i==word.size()) { //���ڿ��� ���� ���� �������� 
			fin=1; //�ش� ���� ���� ��ȭ��ȣ�̰� 
			for(int j=0; j<11; j++) {
				if(!flag || child[j]!=NULL) { //�߰��� ���� ��带 �����ų� 
					flag=true; // �ڽ��߿� �Ҵ�� ��尡 1���� ������ 
					return false; //flag �ʱ�ȭ�ϰ� �ϰ��� ���� ���� 
				}
			}
			return true; //�� ����ϸ� �ϰ��� ���� 
		}
		int pos=word[i]-'0'; //0~10���� �Ҵ��ϱ� ���� 
		if(child[pos]==NULL) { //�Ҵ�Ȱ� ������ 
			child[pos]=new Trie(); //trie�� �����ϰ� �Ҵ� 
		}
		if(fin==1) { flag=false; } //�� ��忡 finǥ�ð� �������� flag=false 
		return insert(i+1, word); //���� �ε��� ���� ���� 
	}

	bool find(int i, string word) { //���ڿ��� �ִ��� Ž�� 
		if(i==word.size()) {
			if(fin==1) return true;
			else return false;
		}
		int pos=word[i]-'0';
		if(child[pos]==NULL) { return false; } //�߰��� �Ҵ�Ȱ� ���°� ã���� ��� ���� ���� 
		
		return child[pos]->find(i+1, word); //���� �ε��� ���� Ž�� 
	}
};
int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--) {
		Trie *trie=new Trie(); //�׽�Ʈ���̽����� ���� 
		int n; cin>>n;
		bool ans=true;
		for(int i=0; i<n; i++) {
			string s; cin>>s;
			if(trie->insert(0,s)) {
				continue;
			}
			else { ans=false; } //1���̶� �ϰ��������� no 
		}
		if(ans) {
			cout<<"YES"<<'\n';
		}
		else cout<<"NO"<<'\n';
		delete trie; //���� 
	}
	return 0;
}
