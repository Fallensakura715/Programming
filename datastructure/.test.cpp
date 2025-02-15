#include <iostream>
#include <vector>
#include <limits>

using namespace std;

constexpr int INF = numeric_limits<int>::max();
constexpr int MAX_V = 10;

vector<vector<int>> dist;//邻接矩阵

void floyd(int n) {
    dist.assign(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    for (int k = 0; k < n; ++k) {//k是中间点
        for (int i = 0; i < n; ++i) {
            if (dist[i][k] == INF) continue;
            for (int j = 0; j < n; ++j) {
                if (dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    return 0;
}