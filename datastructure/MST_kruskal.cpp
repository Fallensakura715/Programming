#include <algorithm>
#include <iostream>

using namespace std;

constexpr int MAX_V = 10;

struct Evode {
    char Head;
    char Tail;
    int weight;
} Edges[MAX_V * (MAX_V - 1) / 2];

struct AMGraph {
    char vexs[MAX_V];
    int arcs[MAX_V][MAX_V];
    int vexnum, arcnum;
};

int parent[MAX_V];

void inputEdges();

int find(int v) {
    if (parent[v] != v) {
        parent[v] = find(parent[v]);
    }
    return parent[v];
}

int locateVex(AMGraph G, char v) {
    int V = G.vexnum;
    for (int i = 0; i < V; ++i) {
        if (G.vexs[i] == v) {
            return i;
        }
    }
    return -1;
}

bool compare(Evode &a, Evode &b) { return a.weight < b.weight; }

int kruskal(AMGraph G) {
    int V = G.vexnum, E = G.arcnum;

    inputEdges();

    for (int i = 0; i < V; ++i) {
        parent[i] = i;
    }

    sort(Edges, Edges + E, compare);

    int edgeCount = 0, result = 0;
    for (int i = 0; i < E && edgeCount < V - 1; ++i) {//遍历顶点
        int h = locateVex(G, Edges[i].Head);
        int t = locateVex(G, Edges[i].Tail);
        int w = Edges[i].weight;

        int hRoot = find(h);
        int tRoot = find(t);

        if (hRoot != tRoot) {
            result += w;
            edgeCount++;
            parent[hRoot] = tRoot; //并查集合并，加上if判断确保不会成环

            cout << Edges[i].Head << "->" << Edges[i].Tail << endl;
        }
    }
    return result;
}
