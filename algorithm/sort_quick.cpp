#include <iostream>
using namespace std;

const int N=1e6 + 10;

int n;
int arr[N];

void quick_sort(int arr[], int l, int r){
    if(l >= r) return;
    int x = arr[r];
    int i = l - 1, j = r + 1;

    while (i < j)
    {
        do i++; while(arr[i] < x);
        do j--; while(arr[j] > x);
        if(i < j) swap(arr[i], arr[j]);
    }
    quick_sort(arr, l, j);
    quick_sort(arr, j+1, r);
}

int partition(int &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    quick_sort(arr,0,n-1);

    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    return 0;
}
