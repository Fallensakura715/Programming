#include <iostream>
using namespace std;

#define MAX_SIZE 100
typedef char SElemtype;
typedef struct {
    SElemtype *base;
    SElemtype *top;
    int stacksize;
}SqStack;//顺序栈

typedef struct StackNode{
    SElemtype data;
    StackNode *next;
}StackNode, *LinkStack;//链栈

bool initLStack(LinkStack &S) {
    S = nullptr;
    return true;
}

bool lStackEmpty(LinkStack &S) {
    if (!S) return true;
    else return false;
}

bool pushL(LinkStack &S, SElemtype e) {
    auto p = new StackNode;
    p->data = e;
    p->next = S;
    S = p;
    return true;
}

bool popL(LinkStack &S, SElemtype &e) {
    if (!S) return false;
    LinkStack p = S;
    e = S->data;
    S = S->next;
    delete p;
    return true;
}

SElemtype getLTop(LinkStack S) {
    if (S) return S->data;
}

bool initSqStack(SqStack &S) {
    S.base = new SElemtype[MAX_SIZE];
    S.top = S.base;
    S.stacksize = MAX_SIZE;
    return true;
}

bool destroySqStack(SqStack &S) {
    if (S.base) {
        delete S.base;
        S.base = S.top = nullptr;
        S.stacksize = 0;
    }
    return true;
}

bool sqStackEmpty(SqStack S) {
    if (S.top == S.base) return true;
    else return false;
}

int sqStackLength(SqStack S) {
    return S.top - S.base;
}

bool clearSqStack(SqStack &S) {
    if (S.base) S.top = S.base;
    return true;
}

bool pushSq(SqStack &S, SElemtype e) {
    if (sqStackEmpty(S)) return false;
    *S.top++ = e;
    return true;
}

bool popSq(SqStack &S, SElemtype &e) {
    if (sqStackEmpty(S)) return false;
    e = *--S.top;
    return true;
}
