#include <iostream>
#include <vector>
using namespace std;

/*
    堆排序
    heapify维护根节点为i的堆的性质
*/
void heapify(vector<int>& arr, int n, int i) {

    int largest = i;
    int left = 2 * i + 1;   // 左子节点,0-based
    int right = 2 * i + 2;  // 右子节点,0-based
    

    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        //递归调整受影响的子堆
        heapify(arr, n, largest);
    }
}

//从叶子节点的父节点开始上滤建堆
//heapify会维护以i为根节点的堆的性质
void heapSort(vector<int>& arr) {
    int n = arr.size();
    
    // 构建堆（从最后一个非叶节点开始向上调整）
    // 建一个大根堆
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    // 逐个从堆顶取出元素
    for (int i = n - 1; i > 0; i--) {
        // 将当前堆顶（最大值）移到数组末尾
        swap(arr[0], arr[i]);
        
        // 对剩余元素重新构建堆,一共有i个元素了(不算数组末尾的)
        heapify(arr, i, 0);
    }
}
