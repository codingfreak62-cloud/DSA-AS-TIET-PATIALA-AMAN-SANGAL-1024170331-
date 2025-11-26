#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {1,2,3,1};
    unordered_set<int> s;
    for (int x : nums) {
        if (s.count(x)) {
            cout << "true";
            return 0;
        }
        s.insert(x);
    }
    cout << "false";
}
