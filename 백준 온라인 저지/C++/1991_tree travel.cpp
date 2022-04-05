#include <iostream>
using namespace std;
class Node {
public:
	char key;
	Node* left;
	Node* right;
	
	Node(char key=0, Node* left=NULL, Node* right=NULL) { //��� ������ 
		this->key=key;
		this->left=left;
		this->right=right;
	}
};

class Tree {
public:
	Node* root; //��Ʈ��带 ����Ű�� ������
	
	Tree(Node* root=NULL) {
		this->root=root;
	}
	
	void Insert(char a, char left, char right) { //��� �߰�����
		if(root==NULL) { //�� Ʈ���̸� 
			root = new Node(a);
			if(left != '.') { root->left = new Node(left); } // -1�� �ڽ��� ���ٴ� �� 
			if(right != '.') { root->right = new Node(right); }
			return;
		}
		else { searchIn(root, a, left, right); } //�ش� ���� ��ġ ã�� 
	}
	
	void searchIn(Node* current, char a, char left, char right) {
		if(current==NULL) { return; }
		if(current->key == a) { //�ٷ� �� ����̸� 
			if(left != '.') { current->left = new Node(left); } //�ڽ� ����� �ֱ� 
			if(right != '.') { current->right = new Node(right); }
			return;
		}
		else { //�ƴϸ� ���� �ڽĺ��� �ٽ� ã��
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
