#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

constexpr int N = 100;

struct Edge {
    int from, to;
    int weight;

    bool operator < (const Edge& other) const { 
        return weight < other.weight; 
    }
};

int parent[N];

int find(int x) {
    if (x != parent[x]) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

int kruskal(vector<Edge>& edges, int n, int m) {
    vector<Edge> res;
    int edge_cnt = 0;

    for (int i = 0; i < n; ++i) parent[i] = i;

    sort(edges.begin(), edges.end());

    for (int i = 0; i < m && edge_cnt < n - 1; ++i) {
        Edge curr = edges[i];

        int root_src = find(curr.from);
        int root_dst = find(curr.to);

        if (root_src != root_dst) {
            res.push_back(curr);
            parent[root_src] = root_dst;
            edge_cnt++;
        }
    }

    if (edge_cnt < n - 1) {
        return -1;
    }

    int total_cost = 0;
    for (const auto& edge : res) {
        total_cost += edge.weight;
    }

    return total_cost;
}

int main() {
    return 0;
}
