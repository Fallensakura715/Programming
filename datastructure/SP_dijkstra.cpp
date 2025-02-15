#include <iostream>
#include <limits>
#include <cstring>

using namespace std;

constexpr int INF = numeric_limits<int>::max();
constexpr int MAX_V = 10;

int dist[MAX_V];
int graph[MAX_V][MAX_V];
bool visited[MAX_V];

void dijkstra(int source, int n) {
    memset(dist, 0x3f, sizeof dist);
    memset(visited, false, sizeof visited);

    dist[1] = 0;

    for (int i = 0; i < n; ++i) {//遍历n次
        int t = -1;
        for (int j = 1; j <= n; ++j) {//遍历所有点
            if (!visited[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }

        if (t == -1) break;

        visited[t] = true;

        for (int j = 0; j < n; ++j) {//用t更新剩下点的最短路
            if (graph[t][j] != INF && dist[t] != INF) {
                dist[j] = min(dist[j], dist[t] + graph[t][j]);
            }
        }
    }
}

int main() {
    return 0;
}
