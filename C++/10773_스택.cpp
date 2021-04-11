#include <iostream>
using namespace std;
int pop(int A[]);
void insert(int A[], int a);
int IsEmpty(int A[]);
int n=-1; //index

int main(void) {
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
	int K; cin>>K;
	int stack[K]={};
	int val; int temp; int sum=0;
	for(int i=0; i<K; i++) {
		cin>>val;
		if(val==0) {
			temp=pop(stack);
		}
		else {
			insert(stack, val);
		}
	}
	temp=0;
	while(!IsEmpty(stack)) {
		temp=pop(stack);
		sum += temp;
	}
	cout<<sum<<'\n';
	return 0;
}

int pop(int A[]) {
	n--;
	return A[n+1];
}

void insert(int A[], int a) {
	n++;
	A[n]=a;
}

int IsEmpty(int A[]) {
	if(n>-1)
		return 0;
	else
		return 1;
}
