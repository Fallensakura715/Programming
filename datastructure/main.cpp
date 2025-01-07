#include <iostream>
using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_V = 32767;
using VertexType = char;
using ArcType = int;
using WeightType = int;

struct AMGraph {
    VertexType vexes[MAX_N];
    ArcType arcs[MAX_N][MAX_N];
    int vex_num, arc_num;
};

struct ArcNode {
    int vex_idx;
    ArcNode *next;
    WeightType weight;
};

struct VNode {
    VertexType data;
    ArcNode *firstarc;
};
using AdjList = VNode[MAX_N];

struct ALGraph {
    AdjList vertices;
    int vex_num, arc_num;
};

bool visited[MAX_N];

int locateVexM(AMGraph G, VertexType u) {
    for (int i = 0; i < G.vex_num; ++i) {
        if (u == G.vexes[i]) return i;
    }
    return -1;
}

//无向网,邻接矩阵
bool createUDN(AMGraph &G) {
    cin >> G.vex_num >> G.arc_num;
    for (int i = 0; i < G.vex_num; i++) cin >> G.vexes[i];
    for (int i = 0; i < G.vex_num; i++)
        for (int j = 0; j < G.vex_num; j++)
            G.arcs[i][j] = MAX_V;

    for (int k = 0; k < G.arc_num; k++) {
        VertexType vex1, vex2;
        WeightType wei;
        cin >> vex1 >> vex2 >> wei;

        int i = locateVexM(G, vex1);
        int j = locateVexM(G, vex2);
        G.arcs[i][j] = wei;
        G.arcs[j][i] = wei;
    }
    return true;
}


int locateVexL(ALGraph G, VertexType u) {
    for (int i = 0; i < G.vex_num; ++i) {
        if (u == G.vertices[i].data) return i;
    }
    return -1;
}

//无向网，邻接表
bool createUDG(ALGraph &G) {
    cin >> G.vex_num >> G.arc_num;
    for (int i = 0; i < G.vex_num; ++i) {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = nullptr;
    }

    for (int k = 0; k < G.arc_num; ++k) {
        VertexType vex1, vex2;
        WeightType wei;
        cin >> vex1 >> vex2 >> wei;

        int i = locateVexL(G, vex1);
        int j = locateVexL(G, vex2);

        auto p1 = new ArcNode;
        p1->vex_idx = j;
        p1->next = G.vertices[i].firstarc;
        p1->weight = wei;
        G.vertices[i].firstarc = p1;

        auto p2 = new ArcNode;
        p2->vex_idx = i;
        p2->next = nullptr;
        p2->weight = wei;
        G.vertices[j].firstarc = p2;
    }
    return true;
}

void DFS(AMGraph G, int vex) {
    cout << " " << vex;
    visited[vex] = true;
    for (int i = 0; i < G.vex_num; ++i) {
        if (G.arcs[vex][i] != MAX_V && !visited[i]) {
            DFS(G, i);
        }
    }
}

void DFS(ALGraph *G,int i) {
    visited[i] = true;
    printf(" %d", i);

    ArcNode *p = G->vertices[i].firstarc;
    while (p) {
        if (!visited[p->vex_idx]) {
            DFS(G, p->vex_idx);
        }
        p = p->next;
    }
}

int main() {
    return 0;
}