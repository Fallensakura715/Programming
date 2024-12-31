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

// createBinaryTree according to inorder and preorder

// BiTNode *createBT(int *pre, int preL, int preR, int *in, int inL, int inR) {
//     if (preL > preR || inL > inR) return nullptr;
//     auto root = new BiTNode(pre[preL], nullptr, nullptr);

//     int rootIn = -1;
//     for (int i = inL; i <= inR; ++i) {
//         if (in[i] == pre[preL]) {
//             rootIn = i;
//             break;
//         }
//     }

//     int lsize = rootIn - inL;
//     root->lchild = createBT(pre, preL + 1, preL + lsize, in, inL, rootIn - 1);
//     root->rchild = createBT(pre, preL + lsize + 1, preR, in, rootIn + 1, inR);
//     return root;
// }

// BiTNode* CreateBT(int* pre, int *in, int n) {
//     if (n == 0) return nullptr;
//     return createBT(pre, 0, n - 1, in, 0, n - 1);
// }


// createBinaryTree according to levelorder
// calculate Binarytree maxWidth

// TreeNode* createTree(TElemSet levelorder[], int n) {
//     if (n == 0 || levelorder[0] == -1) return NULL;

//     TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
//     root->data = levelorder[0];
//     root->left = root->right = NULL;

//     Queue q;
//     initQueue(&q, n + 1);
//     enqueue(&q, root);

//     int i = 1;
//     while (i < n) {
//         TreeNode *pNode = dequeue(&q);
//         if (pNode == NULL) {
//             break;
//         }

//         if (i < n && levelorder[i] != -1) {
//             TreeNode *lNode = (TreeNode *)malloc(sizeof(TreeNode));
//             lNode->data = levelorder[i];
//             lNode->left = lNode->right = NULL;
//             pNode->left = lNode;
//             enqueue(&q, lNode);
//         } i++;

//         if (i < n && levelorder[i] != -1) {
//             TreeNode *rNode = (TreeNode *)malloc(sizeof(TreeNode));
//             rNode->data = levelorder[i];
//             rNode->left = rNode->right = NULL;
//             pNode->right = rNode;
//             enqueue(&q, rNode);
//         } i++;
//     }
//     free(q.arr);
//     return root;
// }

// int Width(TElemSet levelorder[], int n) {
//     if (n == 0 || levelorder == NULL) return 0;
//     TreeNode *root = createTree(levelorder, n);
//     if (!root) return 0;
    
//     Queue q;
//     initQueue(&q, n + 1);
//     enqueue(&q, root);

//     int maxsize = 0;
//     while (!isEmpty(&q)) {
//         int size = (q.rear - q.front + q.capacity) % q.capacity;
//         if (size > maxsize) maxsize = size;

//         for (int i = 0; i < size; i++) {
//             TreeNode *pNode = dequeue(&q);
//             if (pNode->left != NULL) enqueue(&q, pNode->left);
//             if (pNode->right != NULL) enqueue(&q, pNode->right);
//         }
//     }
//     free(q.arr);
//     return maxsize;
// }

int main() {
    return 0;
}
