#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

bool dfs(Node* root, unordered_set<int>& s) {
    if (!root) return false;
    if (s.count(root->val)) return true;
    s.insert(root->val);
    return dfs(root->left, s) || dfs(root->right, s);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(3);

    unordered_set<int> s;
    if (dfs(root, s)) cout << "Duplicates Found";
    else cout << "No Duplicates";
}
