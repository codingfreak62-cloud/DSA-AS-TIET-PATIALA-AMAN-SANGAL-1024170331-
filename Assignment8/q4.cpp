#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int v){
        data=v;
        left=right=NULL;
    }
};

Node* build(Node* root,int v){
    if(!root) return new Node(v);
    int c;
    cin>>c;
    if(c==1) root->left=build(root->left,v);
    else root->right=build(root->right,v);
    return root;
}

int f(Node* r,int mn,int mx){
    if(!r) return 1;
    if(r->data<=mn||r->data>=mx) return 0;
    return f(r->left,mn,r->data)&&f(r->right,r->data,mx);
}

int main(){
    int n,v;
    Node* root=NULL;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v;
        if(!root) root=new Node(v);
        else root=build(root,v);
    }
    cout<<(f(root,-1000000000,1000000000)?1:0);
}
