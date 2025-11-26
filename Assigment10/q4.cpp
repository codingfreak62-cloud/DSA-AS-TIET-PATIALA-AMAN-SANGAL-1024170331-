#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {4,5,1,2,0,4};
    unordered_map<int,int> m;
    for (int x : nums) m[x]++;
    for (int x : nums) {
        if (m[x] == 1) {
            cout << x;
            return 0;
        }
    }
}
