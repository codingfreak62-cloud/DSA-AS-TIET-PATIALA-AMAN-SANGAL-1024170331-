#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {2,3,2,4,3,2};
    unordered_map<int,int> m;
    for (int x : nums) m[x]++;
    for (auto &p : m) cout << p.first << " -> " << p.second << " times\n";
}
