#include <iostream>
#include <cstring>
using namespace std;

typedef struct {
    int weight;
    int parent;
    int left, right;
}HTNode, *HTree;

//找r_dix之前的最小两个根节点
void select(HTree HT, int r_idx, int &s1, int &s2) {
    if (HT[1].weight > HT[2].weight) {
        s2 = 1;
        s1 = 2;
    } else {
        s1 = 1;
        s2 = 2;
    }
    for (int i = 3; i <= r_idx; ++i) {
        if (HT[i].parent == 0) {
            if (HT[i].weight < HT[s1].weight) {
                s2 = s1;
                s1 = i;
            } else if (HT[i].weight < HT[s2].weight) {
                s2 = i;
            }
        }
    }
}

void createHTree(HTree HT, int n) {
    if (n <= 1) return;

    int size = n * 2 - 1;
    HT = new HTNode[size + 1];
    for (int i = 1; i <= size; ++i) {
        HT[i].parent = 0;
        HT[i].left = 0;
        HT[i].right = 0;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> HT[i].weight;
    }

    for (int i = n + 1; i <= size; ++i) {
        int s1, s2;
        select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
        HT[i].left = s1;
        HT[i].right = s2;
    }
}

void createHuffmanCode(HTree HT, char **&HTCode, int n) {
    HTCode = new char*[n + 1];
    char *temp = new char[n];
    temp[n - 1] = '\0';

    for (int i = 1; i <= n; ++i) {
        int start = n - 1;
        int curr = i;
        while (HT[curr].parent != 0) {
            int pa = HT[i].parent;
            curr = pa;

            if (HT[pa].left == i) temp[--start] = '0';
            else temp[--start] = '1';
        }
        HTCode[i] = new char[n - start];
        strcpy(HTCode[i], &temp[start]);
    }
    delete[] temp;
}
