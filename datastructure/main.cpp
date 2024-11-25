#include <iostream>
using namespace std;

const int N = 100010;
int parents[N];
int n, m;

int find(int x) { //·��ѹ��
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
        if (op == 'M') { // �ϲ���������
            parents[find(a)] = find(b);
        }
        if (op == 'Q') { // ��ѯa, b�Ƿ���ͬһ��������
            if (find(a) == find(b)) {
                cout << "Yes";
            }else cout << "No";
        }
    }
    return 0;
}