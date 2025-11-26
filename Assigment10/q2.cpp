#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> A = {1,2,3,4};
    vector<int> B = {3,4,5,6};
    unordered_set<int> s(A.begin(), A.end());
    for (int x : B) {
        if (s.count(x)) cout << x << " ";
    }
}
