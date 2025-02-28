#include <iostream>
#include <limits>
#include <vector>

using namespace std;

constexpr int INF = numeric_limits<int>::max();

int prim(vector<vector<int>>& graph, int n) {
    int res = 0;

    vector<int> key(n, INF);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);

    key[0] = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!inMST[j] && (u == -1 || key[j] < key[u])) {
                u = j;
            }
        }

        inMST[u] = true;
        
        if (key[u] != INF) {
            res += key[u];
        }

        // 更新u到v的边权
        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != INF && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, INF));
    int res = prim(graph, n);
    return 0;
}
