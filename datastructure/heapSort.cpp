#include <iostream>
using namespace std;

using ElemType = int;

//priority_queue
//n是堆的大小，i是堆根节点索引
void heapify(ElemType heap[], int n, int i) {
    int largest = i;
    int left = i * 2;
    int right = i * 2 + 1;

    if (left < n && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right < n && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

void heapSort(ElemType heap[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(heap, n, i);
    }
    for (int i = n - 1; i >= 0; --i) {
        swap(heap[0], heap[i]);
        heapify(heap, i - 0, 0);
    }
}

int main() {
    return 0;
}
