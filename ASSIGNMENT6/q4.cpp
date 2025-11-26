#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *prev, *next;
};

int main() {
    Node* head = 0;
    Node* tail = 0;
    char ch;
    while (cin >> ch) {
        Node* t = new Node;
        t->data = ch;
        t->next = 0;
        t->prev = tail;
        if (tail) tail->next = t;
        else head = t;
        tail = t;
    }
    Node *p = head, *q = tail;
    while (p && q && p != q && q->next != p) {
        if (p->data != q->data) {
            cout << "False";
            return 0;
        }
        p = p->next;
        q = q->prev;
    }
    cout << "True";
}
