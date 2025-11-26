#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode *prev, *next;
};

struct CNode {
    int data;
    CNode *next;
};

int sizeD(DNode* head) {
    int c = 0;
    while (head) {
        c++;
        head = head->next;
    }
    return c;
}

int sizeC(CNode* head) {
    if (!head) return 0;
    int c = 0;
    CNode* p = head;
    do {
        c++;
        p = p->next;
    } while (p != head);
    return c;
}

int main() {
    int n1, n2, x;
    cin >> n1;
    DNode* d = 0;
    for (int i = 0; i < n1; i++) {
        cin >> x;
        DNode* t = new DNode;
        t->data = x; t->next = t->prev = 0;
        if (!d) d = t;
        else {
            DNode* p = d;
            while (p->next) p = p->next;
            p->next = t;
            t->prev = p;
        }
    }
    cin >> n2;
    CNode* c = 0;
    for (int i = 0; i < n2; i++) {
        cin >> x;
        CNode* t = new CNode;
        t->data = x;
        if (!c) {
            c = t;
            c->next = c;
        } else {
            CNode* p = c;
            while (p->next != c) p = p->next;
            p->next = t;
            t->next = c;
        }
    }
    cout << sizeD(d) << " " << sizeC(c);
}
