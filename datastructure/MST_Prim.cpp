#include <iostream>
#include <vector>
#include <limits>

using namespace std;

constexpr int MVNum = 100;
constexpr int INF = numeric_limits<int>::max();

typedef struct{
    char vexs[MVNum];
    int arcs[MVNum][MVNum];
    int vexnum,arcnum;
}AMGraph;

int prim(AMGraph G) {
    int V = G.vexnum;
    
    vector<int> key(V, INF);
    vector<bool> inMST(V, false);

    key[0] = 0;
    int result = 0;

    for (int i = 0; i < V; ++i) {
        int u = -1;
        for (int j = 0; j < V; ++j) {
            if (!inMST[j] && key[j] < minKey) {
                u = j;
            }
        }

        result += key[u];
        inMST[u] = true;

        //更新剩下顶点到刚加入MST点的权重
        for (int j = 0; j < V; ++j) {
            if (G.arcs[u][j] > 0 && !inMST[j] && G.arcs[u][j] < key[j]) {
                key[j] = G.arcs[u][j];
            }
        }
    }
    return result;
}
