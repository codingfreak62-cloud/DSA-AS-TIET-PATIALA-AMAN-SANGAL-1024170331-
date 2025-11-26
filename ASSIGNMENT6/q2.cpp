#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insert(Node* head, int x) {
    Node* t = new Node;
    t->data = x;
    if (!head) {
        t->next = t;
        return t;
    }
    Node* p = head;
    while (p->next != head) p = p->next;
    p->next = t;
    t->next = head;
    return head;
}

int main() {
    Node* head = 0;
    int x;
    while (cin >> x) head = insert(head, x);
    if (!head) return 0;

    Node* p = head;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << head->data;
}
