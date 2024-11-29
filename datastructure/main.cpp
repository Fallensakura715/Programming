#include <iostream>
#include <cstring>
using namespace std;

constexpr int N = 1e5 + 10;
constexpr int MOD = 1e5 + 3;
int h[N], e[N], next_e[N], idx = 0;
//这个是拉链法
//e是个模拟链表
//h是hash表示h[i]的值存在了e[h[i]]里

void insert(int k) {
    e[idx] = k;
    next_e[idx] = h[k];
    h[k] = idx++;
}

bool find(int x, int k) {
    for (int i = h[k]; i != -1; i = next_e[i]) {
        if (e[i] == x) return true;
    }
    return false;
}

int main() {
    int n;
    memset(h, -1, sizeof(h));
    cin >> n;
    while (n--) {
        char ch[2];
        int x;
        scanf("%s%d", ch, &x);
        int k = (x % MOD + MOD) % MOD;
        if (ch[0] == 'I') insert(k);
        if (ch[0] == 'Q') {
            if (find(x, k)) puts("Yes\n");
            else puts("No\n");
        }
    }
    return 0;
}