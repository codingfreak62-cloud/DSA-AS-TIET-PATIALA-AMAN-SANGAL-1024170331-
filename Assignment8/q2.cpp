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

Node* insert(Node* root,int v){
    if(!root) return new Node(v);
    if(v<root->data) root->left=insert(root->left,v);
    else if(v>root->data) root->right=insert(root->right,v);
    return root;
}

Node* searchRec(Node* r,int k){
    if(!r || r->data==k) return r;
    if(k<r->data) return searchRec(r->left,k);
    return searchRec(r->right,k);
}

Node* searchIter(Node* r,int k){
    while(r){
        if(r->data==k) return r;
        if(k<r->data) r=r->left;
        else r=r->right;
    }
    return NULL;
}

Node* findMin(Node* r){
    while(r && r->left) r=r->left;
    return r;
}

Node* findMax(Node* r){
    while(r && r->right) r=r->right;
    return r;
}

Node* suc(Node* root,int k){
    Node* t=searchRec(root,k);
    if(!t) return NULL;
    if(t->right) return findMin(t->right);
    Node* s=NULL;
    while(root){
        if(k<root->data){
            s=root;
            root=root->left;
        }else if(k>root->data) root=root->right;
        else break;
    }
    return s;
}

Node* pre(Node* root,int k){
    Node* t=searchRec(root,k);
    if(!t) return NULL;
    if(t->left) return findMax(t->left);
    Node* p=NULL;
    while(root){
        if(k>root->data){
            p=root;
            root=root->right;
        }else if(k<root->data) root=root->left;
        else break;
    }
    return p;
}

int main(){
    Node* root=NULL;
    int n,v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v;
        root=insert(root,v);
    }

    int ch,k;
    cin>>ch;
    switch(ch){
        case 1:
            cin>>k;
            cout<<(searchRec(root,k)?"Found":"Not Found");
            break;
        case 2:
            cin>>k;
            cout<<(searchIter(root,k)?"Found":"Not Found");
            break;
        case 3:
            cout<<findMax(root)->data;
            break;
        case 4:
            cout<<findMin(root)->data;
            break;
        case 5:
            cin>>k;
            if(suc(root,k)) cout<<suc(root,k)->data; else cout<<"None";
            break;
    }
}
