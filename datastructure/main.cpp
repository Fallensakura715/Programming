#include <iostream>
using namespace std;

typedef int Elemtype;
typedef struct DuLNode{
    Elemtype data;
    struct DuLNode *prior, *next;
}DuLNode, *DuLinkList;

void InitList(DuLinkList &L) {
    L = new DuLNode;
    L->prior = nullptr;
    L->next = nullptr;
}

DuLinkList GetElemP_DuL(DuLinkList &L, int i) {
    if (!L || i < 1) return nullptr;
    int idx = 1;
    auto p = L;
    while (idx < i && p) {
        p = p->next;
        idx++;
    }
    return i == idx ? p : nullptr;
}

bool ListDelete_DuL(DuLinkList &L, int i, Elemtype &e) {
    if (!L) return false;
    auto p = GetElemP_DuL(L, i);
    if (!p) return false;
    e = p->data;
    p->prior->next = p->next;
    if (p->next) {  //如果不是最后一个
        p->next->prior = p->prior;
    }
    delete p;
    return true;
}

bool insert(DuLinkList &L, int i, Elemtype e) {
    if (!L) return false;
    auto p = GetElemP_DuL(L, i);
    if (!p) return false;
    auto newNode = new DuLNode;
    newNode->data = e;
    newNode->prior = p->prior;
    newNode->next = p->next;
    p->prior->next = newNode;
    p->prior = newNode;
    return true;
}

int main() {
    DuLinkList L;
    InitList(L);

    insert(L, 1, 10);

    Elemtype e;
    ListDelete_DuL(L, 1, e);

    DuLinkList p = L->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    return 0;
}