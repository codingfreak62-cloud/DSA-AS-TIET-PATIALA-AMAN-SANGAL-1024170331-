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

Node* insert(Node* r,int v){
    if(!r) return new Node(v);
    if(v<r->data) r->left=insert(r->left,v);
    else if(v>r->data) r->right=insert(r->right,v);
    return r;
}

Node* findMin(Node* r){
    while(r && r->left) r=r->left;
    return r;
}

Node* del(Node* r,int k){
    if(!r) return r;
    if(k<r->data) r->left=del(r->left,k);
    else if(k>r->data) r->right=del(r->right,k);
    else{
        if(!r->left){
            Node* t=r->right;
            delete r;
            return t;
        }
        if(!r->right){
            Node* t=r->left;
            delete r;
            return t;
        }
        Node* t=findMin(r->right);
        r->data=t->data;
        r->right=del(r->right,t->data);
    }
    return r;
}

int maxDepth(Node* r){
    if(!r) return 0;
    int L=maxDepth(r->left);
    int R=maxDepth(r->right);
    return (L>R?L:R)+1;
}

int minDepth(Node* r){
    if(!r) return 0;
    int L=minDepth(r->left);
    int R=minDepth(r->right);
    if(!r->left||!r->right) return L+R+1;
    return (L<R?L:R)+1;
}

int main(){
    Node* root=NULL;
    int ch,v;
    cin>>ch;
    switch(ch){
        case 1:
            cin>>v;
            root=insert(root,v);
            cout<<root->data;
            break;
        case 2:
            cin>>v;
            root=del(root,v);
            if(root) cout<<root->data;
            break;
        case 3:
            cout<<maxDepth(root);
            break;
        case 4:
            cout<<minDepth(root);
            break;
    }
}
