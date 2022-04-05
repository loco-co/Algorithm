#include<iostream>
using namespace std;
int p[64][64];
void Quadtree(int a, int b, int size);
    
int main(void) {
    int n=0; cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>p[i][j];
    
    Quadtree(0,0,n);
    return 0;
}

void Quadtree(int a, int b, int size) {
    int temp=p[a][b]; bool result=true;
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            if(temp!=p[a+i][b+j]) result=false;
    
    if(result) {
        cout<<temp; return;
    }
    else {
        cout<<'(';
        Quadtree(a,b,size/2);
        Quadtree(a,b+size/2,size/2);
        Quadtree(a+size/2,b,size/2);
        Quadtree(a+size/2,b+size/2,size/2);
        cout<<')';    
    }
}
