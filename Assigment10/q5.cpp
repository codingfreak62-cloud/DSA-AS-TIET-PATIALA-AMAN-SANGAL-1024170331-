#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(NULL) {}
};

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;

    unordered_set<Node*> s;
    Node* cur = n1;

    while (cur) {
        if (s.count(cur)) {
            cout << "true";
            return 0;
        }
        s.insert(cur);
        cur = cur->next;
    }
    cout << "false";
}
