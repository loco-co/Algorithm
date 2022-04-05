#include <iostream>
using namespace std;
class Node {
public:
	char key;
	Node* left;
	Node* right;
	
	Node(char key=0, Node* left=NULL, Node* right=NULL) { //노드 생성자 
		this->key=key;
		this->left=left;
		this->right=right;
	}
};

class Tree {
public:
	Node* root; //루트노드를 가리키는 포인터
	
	Tree(Node* root=NULL) {
		this->root=root;
	}
	
	void Insert(char a, char left, char right) { //노드 추가연산
		if(root==NULL) { //빈 트리이면 
			root = new Node(a);
			if(left != '.') { root->left = new Node(left); } // -1은 자식이 없다는 뜻 
			if(right != '.') { root->right = new Node(right); }
			return;
		}
		else { searchIn(root, a, left, right); } //해당 값의 위치 찾기 
	}
	
	void searchIn(Node* current, char a, char left, char right) {
		if(current==NULL) { return; }
		if(current->key == a) { //바로 그 노드이면 
			if(left != '.') { current->left = new Node(left); } //자식 만들어 주기 
			if(right != '.') { current->right = new Node(right); }
			return;
		}
		else { //아니면 왼쪽 자식부터 다시 찾기
			searchIn(current->left, a, left, right);
			searchIn(current->right, a, left, right);
		}
	}
	
	void Inorder(Node* current) { // inorder
		if(current==NULL) { return; }
		else {
			Inorder(current->left);
			cout<<current->key;
			Inorder(current->right);
		}
	}
	
	void Preorder(Node* current) {
		if(current==NULL) { return; }
		else {
			cout<<current->key;
			Preorder(current->left);
			Preorder(current->right);
		}
	}
	
	void Postorder(Node* current) {
		if(current==NULL) { return; }
		else {
			Postorder(current->left);
			Postorder(current->right);
			cout<<current->key;
		}
	}
};

int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	char a,b,c;
	int n;
	cin>>n;
	Tree T;
	for(int i=0; i<n; i++) {
		cin>>a>>b>>c;
		T.Insert(a,b,c);
	}
	T.Preorder(T.root); cout<<'\n';
	T.Inorder(T.root); cout<<'\n';
	T.Postorder(T.root);
	return 0;
}
