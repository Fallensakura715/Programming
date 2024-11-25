#include <iostream>
using namespace std;

constexpr int N = 100010;
int n, m;
int parents[N], psize[N];

int find(int x) { // 路径压缩
    if (parents[x] != x) {
        parents[x] = find(parents[x]);
    }
    return parents[x];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        parents[i] = i;
        psize[i] = 1;
    }
    while (m--) {
        char op[5];
        int a, b;
        cin >> op;
        if (op[1] == '2') {
            cin >> a;
            cout << psize[find(a)];
            continue;
        }
        cin >> a >> b;
        if (op[0] == 'C') {
            if (find(a) == find(b)) continue;
            psize[find(b)] += psize[find(a)]; // 合并的时候先合并size，再给俩集合合并
            parents[find(a)] = find(b);
        }else if (op[1] == '1') {
            if (find(a) == find(b)) {
                cout << "Yes";
            }else cout << "No";
        }
    }
    return 0;
}
