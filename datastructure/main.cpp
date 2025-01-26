#include <iostream>
#include <vector>
#include <climits>
using namespace std;

constexpr int MVNum = 100;
typedef struct{
    char vexs[MVNum];
    int arcs[MVNum][MVNum];
    int vexnum,arcnum;
}AMGraph;

// MST Prim算法 邻接矩阵实现
int prim(AMGraph G) {
    int V = G.vexnum;
    int key[V];
    vector<bool> inMST(V, false);

    key[0] = 0;
    int result = 0;

    for (int i = 0; i < V; ++i) {
        int u = -1;
        int minKey = INT_MAX;

        for (int j = 0; j < V; ++j) {
            if (!inMST[j] && key[j] < minKey) {
                u = j;
                minKey = key[j];
            }
        }

        result += key[u];
        inMST[u] = true;

        for (int j = 0; j < V; ++j) {
            if (G.arcs[u][j] > 0 && !inMST[j] && G.arcs[u][j] < key[j]) {
                key[j] = G.arcs[u][j];
            }
        }
    }
    return result;
}