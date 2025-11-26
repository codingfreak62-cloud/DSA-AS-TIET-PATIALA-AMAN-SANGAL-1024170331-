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
    int x;
    cin>>x;
    if(x==1) root->left=insert(root->left,v);
    else root->right=insert(root->right,v);
    return root;
}

void preorder(Node* r){
    if(r){
        cout<<r->data<<" ";
        preorder(r->left);
        preorder(r->right);
    }
}

void inorder(Node* r){
    if(r){
        inorder(r->left);
        cout<<r->data<<" ";
        inorder(r->right);
    }
}

void postorder(Node* r){
    if(r){
        postorder(r->left);
        postorder(r->right);
        cout<<r->data<<" ";
    }
}

int main(){
    int n,v;
    Node* root=NULL;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v;
        if(!root) root=new Node(v);
        else root=insert(root,v);
    }
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
}
