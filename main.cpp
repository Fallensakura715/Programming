#include <iostream>
#include <malloc.h>
using namespace std;

typedef char ElemType;
typedef struct LNode    //定义单链表结点类型
{
    ElemType data;
    struct LNode *next;
} LinkList;

void InitList(LinkList *&L){
    L = (LinkList*) malloc(sizeof(LNode));
    if (!L) return;
    L->next = nullptr;
}  //初始化一个为空的单链表。

void DestroyList(LinkList *&L){
    if (!L) return;
    LinkList *p = L,*q = nullptr;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    L = nullptr;
}  //销毁单链表。

void DispList(LinkList *L){
    if (!L || !L->next) {
        printf("\n");
        return;
    }
    LinkList *p = L->next;
    while (p) {
        printf("%c", p->data);
        printf(" ");
        p = p->next;
    }
    printf("\n");
}  //顺序输出链表每个结点，每个结点元素值以空格符间隔，以换行符结束。

bool ListInsert(LinkList *&L,int i,ElemType e){
    if (i <= 0) return false;
    int cnt = 0;
    LinkList *p = L;
    while (p && cnt<i-1) {
        p = p->next;
        cnt++;
    }
    if (!p) return false;
    LinkList *newNode = (LinkList*) malloc(sizeof(LNode));
    if (!newNode) return false;
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return true;
} //在链表第i个结点位置处，插入元素值为e的结点，若插入成功，返回true，否则返回false.

bool ListDelete(LinkList *&L,int i,ElemType &e){
    if (i<=0 || !L || !L->next) return false;
    LinkList *p = L,*q;
    int cnt=0;
    while (p->next && cnt<i-1){
        p = p->next;
        cnt++;
    }
    if (!p->next) return false;
    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return true;
} //删除链表第i个结点，返回删除结点的元素值e，若删除成功，返回true，否则返回false

LinkList* buildLinkedList(int* arr, int n){
    LinkList* newNode=(LinkList*) malloc(sizeof(LNode));
    newNode->next = nullptr;
    LinkList* p = newNode;
    for (int i = 0; i < n; ++i) {
        LinkList* newNode1 = (LinkList*) malloc(sizeof(LNode));
        newNode1->data = arr[i];
        newNode1->next = nullptr;
        p->next = newNode1;
        p = p->next;
    }
    return newNode;
} //尾插法建立单链表

void CreateListF(LinkList *&L,int n){
    L = nullptr;
    for (int i = 0; i < n; ++i) {
        LinkList* newNode=(LinkList*) malloc(sizeof(LNode));
        if (!newNode) return;
        cin >> newNode->data;
        newNode->next = L;
        L = newNode;
    }
} //头插法建立单链表