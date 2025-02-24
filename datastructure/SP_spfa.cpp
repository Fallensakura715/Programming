#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using namespace std;

constexpr int INF = numeric_limits<int>::max();

struct Edge {
    int to, weight;
};

//spfa算法，能处理负权图，o(m),最坏o(nm)

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
    }

    vector<bool> inQueue(n, false);
    vector<int> dist(n, INF);
    vector<int> countRelax(n, 0);
    queue<int> q;

    dist[0] = 0;
    q.push(0);
    inQueue[0] = true;

    bool negativeCycle = false;
    while (!q.empty()) {
        int u = q.front();//队列里存的是所有变小过的dist[],只要队列不空就用dist[]+w更新其他点
        q.pop();
        inQueue[u] = false;

        for (const auto& edge: graph[u]) {
            int v = edge.to;
            int w = edge.weight;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = true;

                    countRelax[v]++;
                    if (countRelax[v] >= n) {//负权边会一直绕圈走，countRelax就会很大
                        negativeCycle = true;
                        break;
                    }
                }
            }
        }
        if (negativeCycle) break;
    }

    return 0;
}
