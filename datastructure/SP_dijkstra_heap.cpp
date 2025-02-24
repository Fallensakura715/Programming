#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>
#include <vector>

using namespace std;

constexpr int INF = numeric_limits<int>::max();
constexpr int MAX_V = 10;

struct edge {
    int to;
    int weight;
};

vector<vector<edge>> graph;
vector<int> dist;
int n;

void dijkstra(int source) {
    dist.assign(n, INF);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;//自定义小根堆
    heap.emplace(0, source);

    while (!heap.empty()) {
        auto curr = heap.top();
        heap.pop();

        int d = curr.first;
        int u = curr.second;

        if (d > dist[u]) continue;

        for (const edge &e: graph[u]) {
            int v = e.to;
            if (dist[v] > d + e.weight) {
                heap.emplace(dist[v], v);
            }
        }
    }
    
}

int main() {
    return 0;
}
