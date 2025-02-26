#include <iostream>
#include <queue>

using namespace std;

int main() {
    vector<vector<int>> adj;//邻接表
    int v;
    cin >> v;
    vector<int> inDegree(v, 0);

    for (int i = 0; i < v; ++i) {
        for (int vex : adj[i]) {
            inDegree[vex]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; ++i) {
        if (inDegree[i] == 0) q.push(i);
    }

    vector<int> topo;
    int vex_count = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);

        for (int vex : adj[u]) {
            inDegree[vex]--;
            if (inDegree[vex] == 0) {
                q.push(vex);
            }
        }

        vex_count++;
    }

    if (vex_count != v) cout << "图存在环，没有topo序列";
    for (int i : topo) cout << i << ' ';

    return 0;
}