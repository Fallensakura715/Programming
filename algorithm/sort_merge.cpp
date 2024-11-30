#include <iostream>
using namespace std;
#define N 10000010

int arr[N], temp[N];

void merge_sort(int arr[], int l, int r){
    if (l >= r) return;
    int x = (l + r) / 2;
    merge_sort(arr, l, x);
    merge_sort(arr, x+1, r);

    int temp_idx = 0, i = l, j = x + 1;
    while (i <= x && j <= r){
        if (arr[i] <= arr[j])
            temp[temp_idx++] = arr[i++];
        else
            temp[temp_idx++] = arr[j++];
    }
    while (i <= x) temp[temp_idx++] = arr[i++];
    while (j <= r) temp[temp_idx++] = arr[j++];
    for (int k = 0; k < temp_idx; ++k) {
        arr[l + k] = temp[k];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    merge_sort(arr, 0, n-1);

    for (int i = 0; i < n; ++i) {
        printf("%d",arr[i]);
    }
    return 0;
}
