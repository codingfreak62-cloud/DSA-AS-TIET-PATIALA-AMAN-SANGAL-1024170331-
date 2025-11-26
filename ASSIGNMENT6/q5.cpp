#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n, x, c;
    cin >> n >> c;

    Node* head = 0;
    Node* p = 0;

    for (int i = 0; i < n; i++) {
        cin >> x;
        Node* t = new Node;
        t->data = x;
        t->next = 0;
        if (!head) {
            head = t;
            p = t;
        } else {
            p->next = t;
            p = t;
        }
    }

    if (c == 1) p->next = head;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            cout << "Circular";
            return 0;
        }
    }
    cout << "Not Circular";
}
