#include <iostream>
using namespace std;

const int N = 100010;
int parents[N];
int n, m;

int find(int x) { //路径压缩
    if (parents[x] != x) {
        parents[x] = find(parents[x]);
    }
    return parents[x];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        parents[i] = i;
    }
    while (m --) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == 'M') { // 合并两个集合
            parents[find(a)] = find(b);
        }
        if (op == 'Q') { // 查询a, b是否在同一个集合里
            if (find(a) == find(b)) {
                cout << "Yes";
            }else cout << "No";
        }
    }
    return 0;
}
