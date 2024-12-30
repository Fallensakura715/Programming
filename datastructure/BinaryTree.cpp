#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class BiTree {
    using ElemType = int;

private:
    ElemType value;
    BiTree *lchild;
    BiTree *rchild;

public:
    BiTree(ElemType val) : value(val), lchild(nullptr), rchild(nullptr) {}

    bool createBitree(BiTree *&T) {
        ElemType e;
        cin >> e;
        if (e == -1) {
            T = nullptr;
            return true;
        } else {
            T = new BiTree(e);
            createBitree(T->lchild);
            createBitree(T->rchild);
            return true;
        }
    }

    void preOrderTraverse() {
        cout << value << " ";
        if (lchild) lchild->preOrderTraverse();
        if (rchild) rchild->preOrderTraverse();
    }

    void inOrderTraverse() {
        if (lchild) lchild->inOrderTraverse();
        cout << value << " ";
        if (rchild) rchild->inOrderTraverse();
    }

    void inOrderStackTraverse(BiTree *T) {
        stack<BiTree *> stack1;
        BiTree *p = T;

        while (p || !stack1.empty()) {
            while (p) {
                stack1.push(p);
                p = p->lchild;
            }

            p = stack1.top();
            stack1.pop();
            cout << p->value << " ";

            p = p->rchild;
        }
    }

    void levelOrderTraverse(BiTree *T) {
        if (!T) return;
        queue<BiTree *> queue1;
        queue1.push(T);

        while (!queue1.empty()) {
            BiTree *p = queue1.front();
            queue1.pop();

            cout << p->value << " ";

            if (p->lchild) queue1.push(p->lchild);
            if (p->rchild) queue1.push(p->rchild);
        }
    }

    void postOrderTraverse() const {
        if (lchild) lchild->postOrderTraverse();
        if (rchild) rchild->postOrderTraverse();
        cout << value << " ";
    }

    BiTree *copy(BiTree *T) {
        if (!T) {
            return nullptr;
        } else {
            BiTree *newBiTree = new BiTree(T->value);
            newBiTree->lchild = copy(T->lchild);
            newBiTree->rchild = copy(T->rchild);
            return newBiTree;
        }
    }

    int depth(BiTree *T) {
        if (!T) return 0;
        else {
            int m = depth(T->lchild);
            int n = depth(T->rchild);
            return (m > n) ? m + 1 : n + 1;
        }
    }

    int nodeCount(BiTree *T) {
        if (!T) return 0;
        else return nodeCount(T->lchild) + nodeCount(T->rchild) + 1;
    }

    int leafCount(BiTree *T) {
        if (!T) return 0;
        if (!T->lchild && !T->rchild) return 1;
        else return leafCount(T->lchild) + leafCount(T->rchild);
    }
};

int main() {
    return 0;
}
