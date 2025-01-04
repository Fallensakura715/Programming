#include <iostream>
#include <cstring>
using namespace std;

constexpr int N = 1e5 + 10;
constexpr int MOD = 1e5 + 3;
int h[N], e[N], next_e[N], idx = 0;
//这个是链式法
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

// typedef struct HashNode{
//     int  key;
//     struct HashNode *next;
// }HashNode,* HashTable;

// void CreateHash(HashTable HT[], int n) {
//     for (int i = 0; i < n; ++i) {
//         int k;
//         cin >> k;
//         int idx = (k % P + P) % P;

//         HashNode* node = new HashNode;
//         node->key = k;
//         node->next = nullptr;

//         if (HT[idx] == nullptr) {
//             HT[idx] = node;
//         }
//         else {
//             HashNode* p = HT[idx];
//             while (p->next != nullptr) {
//                 p = p->next;
//             }
//             p->next = node;
//         }
//     }
// }

// 计算平均查找长度
// 对于第 i 个非空桶，记该桶中链表长度为 c_i，成功查找其中任意元素时平均需要 (c_i + 1) / 2 次比较
// float ASL(HashTable HT[]) {
//     int elems = 0;
//     float weightedSum = 0.0f;

//     for (int i = 0; i < P; ++i) {
//         int len = 0;
//         HashNode* p = HT[i];
//         while (p) {
//             len++;
//             p = p->next;
//         }

//         if (len > 0) {
//             weightedSum += len * ((len + 1.0f) / 2.0f);
//             elems += len;
//         }
//     }

//     if (elems == 0) {
//         return 0.0f;
//     }
//     return weightedSum / static_cast<float>(elems);
// }
