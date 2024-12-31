#include <iostream>
using namespace std;

class RBTree {
    using ElemType = int;
    enum Color { RED, BLACK };
private:
    struct RBTNode {
        ElemType data;
        Color color;
        RBTNode *left;
        RBTNode *right;
        RBTNode *parent;
        RBTNode(ElemType data) : data(data), left(nullptr), right(nullptr), parent(nullptr) {}
    };
    RBTNode *root;
    RBTNode *TNULL;

    void initNIL(RBTNode* node, RBTNode* parent) {
        node->data = 0;
        node->color = BLACK;
        node->left = nullptr;
        node->right = nullptr;
        node->parent = parent;
    }

//  左旋
//  当在某个结点p上，做左旋操作时，我们假设它的右孩子y不是NIL，p可以为任何不是NIL的左孩子结点。
//  左旋以p到y之间的链为“支轴”进行，它使y成为该孩子树新的根，而y的左孩子b则成为p的右孩子。
//    *p*            y
//    / \           / \
//   a   y    ->  *p*  c
//      /\        /\
//     b  c      a  b
    void leftRotate(RBTNode *p) {
        RBTNode *y = p->right;
        p->right = y->left;
        if (y->left != TNULL) y->left->parent = p;
        y->parent = p->parent;
        if (p->parent == nullptr) this->root = y;
        else if (p == p->parent->left) p->parent->left = y;
        else p->parent->right = y;
        y->left = p;
        p->parent = y;
    }
//     P             y
//    / \           / \
//   y   a    ->   b   P
//  /\                 /\
// b  c               a  c
    void rightRotate(RBTNode *p) {
        RBTNode *y = p->left;
        p->left = y->right;
        if (y->right != TNULL) y->right->parent = p;
        y->parent = p->parent;
        if (p->parent == nullptr) this->root = y;
        else if (p == p->parent->left) p->parent->left = y;
        else p->parent->right = y;
        y->right = p;
        p->parent = y;
    }
    void insertFix(RBTNode* k) {
        RBTNode* u;
        while (k->parent->color == RED) {
            if (k->parent == k->parent->parent->right) {
                u = k->parent->parent->left;

                if (u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                }
                else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }

                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    leftRotate(k->parent->parent);
                }
            }
            else {
                u = k->parent->parent->right;

                if (u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                }
                else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }

                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root)
                break;
        }
        root->color = BLACK;
    }
    void inorderHelper(RBTNode *node) {
        if (node != TNULL && node != nullptr) {
            inorderHelper(node->left);
            cout << node->data << "(" << (node->color == RED ? "R" : "B") << ") ";
            inorderHelper(node->right);
        }
    }
    RBTNode *searchHelper(RBTNode *node, ElemType x) {
        if (node == nullptr || x == node->data) return node;
        if (x < node->data) return searchHelper(node->left, x);
        else return searchHelper(node->right, x);
    }

public:
    RBTree() {
        TNULL = new RBTNode(0);
        TNULL->color = BLACK;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
    }

    void insert(ElemType x) {
        RBTNode* newNode = new RBTNode(x);
        newNode->data = x;
        newNode->left = TNULL;
        newNode->right = TNULL;
        newNode->color = RED;
        newNode->parent = nullptr;

        RBTNode *p = this->root;
        RBTNode *q = nullptr;
        while (p != TNULL) {
            q = p;
            if (newNode->data < p->data) p = p->left;
            else p = p->right;
        }

        newNode->parent = q;
        if (q == nullptr) root = q;
        else if (newNode->data < q->data) q->left = newNode;
        else q->right = newNode;

        if (newNode->parent == nullptr) {
            newNode->color = BLACK;
            return;
        }
        if (newNode->parent->parent == nullptr) return;
        insertFix(newNode);
    }
    RBTNode* search(ElemType x) {
        return searchHelper(this->root, x);
    }
    void inorder() {
        inorderHelper(this->root);
    }
};
