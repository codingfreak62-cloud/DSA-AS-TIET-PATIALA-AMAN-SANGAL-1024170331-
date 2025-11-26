#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

vector<int> parent, rnk;

int find(int x) {
    if (x != parent[x]) parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<Edge> edges(e);
    for (int i = 0; i < e; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;

    parent.resize(n);
    rnk.assign(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });

    int cost = 0;
    for (auto &ed : edges) {
        if (find(ed.u) != find(ed.v)) {
            cost += ed.w;
            unite(ed.u, ed.v);
            cout << ed.u << " " << ed.v << " " << ed.w << endl;
        }
    }
    cout << "MST cost = " << cost;
}
