#include <iostream>
using namespace std;

// Doubly Linked List
struct DNode {
    int data;
    DNode *prev, *next;
};

DNode* insertD(DNode* head, int x, int pos) {
    DNode* t = new DNode;
    t->data = x; t->prev = t->next = 0;
    if (pos == 1) {
        t->next = head;
        if (head) head->prev = t;
        return t;
    }
    DNode* p = head;
    for (int i = 1; p && i < pos - 1; i++) p = p->next;
    if (!p) return head;
    t->next = p->next;
    if (p->next) p->next->prev = t;
    p->next = t;
    t->prev = p;
    return head;
}

DNode* deleteD(DNode* head, int x) {
    DNode* p = head;
    while (p && p->data != x) p = p->next;
    if (!p) return head;
    if (p == head) head = head->next;
    if (p->next) p->next->prev = p->prev;
    if (p->prev) p->prev->next = p->next;
    delete p;
    return head;
}

bool searchD(DNode* head, int x) {
    while (head) {
        if (head->data == x) return true;
        head = head->next;
    }
    return false;
}

// Circular Linked List
struct CNode {
    int data;
    CNode *next;
};

CNode* insertC(CNode* head, int x, int pos) {
    CNode* t = new CNode;
    t->data = x;
    if (!head) {
        t->next = t;
        return t;
    }
    if (pos == 1) {
        CNode* p = head;
        while (p->next != head) p = p->next;
        p->next = t;
        t->next = head;
        return t;
    }
    CNode* p = head;
    for (int i = 1; p->next != head && i < pos - 1; i++)
        p = p->next;
    t->next = p->next;
    p->next = t;
    return head;
}

CNode* deleteC(CNode* head, int x) {
    if (!head) return head;
    CNode *p = head, *q = 0;
    do {
        if (p->data == x) break;
        q = p;
        p = p->next;
    } while (p != head);
    if (p->data != x) return head;
    if (p == head && head->next == head) {
        delete head;
        return 0;
    }
    if (p == head) {
        CNode* t = head;
        while (t->next != head) t = t->next;
        head = head->next;
        t->next = head;
        delete p;
        return head;
    }
    q->next = p->next;
    delete p;
    return head;
}

bool searchC(CNode* head, int x) {
    if (!head) return false;
    CNode* p = head;
    do {
        if (p->data == x) return true;
        p = p->next;
    } while (p != head);
    return false;
}

int main() {
    DNode* dhead = 0;
    CNode* chead = 0;
    int ch, listType, x, pos;

    while (1) {
        cin >> listType;
        if (listType == 1) {
            cin >> ch;
            if (ch == 1) {
                cin >> x >> pos;
                dhead = insertD(dhead, x, pos);
            } else if (ch == 2) {
                cin >> x;
                dhead = deleteD(dhead, x);
            } else if (ch == 3) {
                cin >> x;
                cout << (searchD(dhead, x) ? 1 : 0);
            } else return 0;
        }

        else if (listType == 2) {
            cin >> ch;
            if (ch == 1) {
                cin >> x >> pos;
                chead = insertC(chead, x, pos);
            } else if (ch == 2) {
                cin >> x;
                chead = deleteC(chead, x);
            } else if (ch == 3) {
                cin >> x;
                cout << (searchC(chead, x) ? 1 : 0);
            } else return 0;
        }

        else return 0;
    }
}
