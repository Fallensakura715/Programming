#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int INF = numeric_limits<int>::max();

struct Edge {
    int u, v, weight;
};

//bellman-ford算法，能处理负权图，当有边数限制时用

int main() {
    int n;
    cin >> n;
    vector<Edge> edges(n);
    for (int i = 0; i < n; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    int src;
    cin >> src;

    vector<int> dist(n, INF);
    dist[src] = 0;

    for (int i = 0; i < n - 1; ++i) {
        vector<int> backup(dist);//可以不备份，备份防止有边数限制的时候出现乱更新
        bool updated = false;
        for (const auto& e : edges) {
            if (dist[e.u] != INF && backup[e.u] + e.weight < dist[e.v]) {
                dist[e.v] = backup[e.u] + e.weight;
                updated = true;
            }
        }
        if (!updated) break;
    }

    bool canReach = true;
    for (const auto& e : edges) {//检测是否有负权环
        if (dist[e.u] != INF && dist[e.u] + e.weight < dist[e.v]) {
            canReach = false;
        }
    }

    int dest;
    cin >> dest;
    cout << dist[dest];

    return 0;
}
