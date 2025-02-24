#include <iostream>
#include <limits>
#include <vector>

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
        bool updated = false;
        for (const auto& e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.weight < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.weight;
            }
        }
        if (!updated) break;
    }

    bool canReach = true;
    for (const auto& e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.weight < dist[e.v]) {
            canReach = false;
        }
    }

    int dest;
    cin >> dest;
    cout << dist[dest];
    
    return 0;
}
