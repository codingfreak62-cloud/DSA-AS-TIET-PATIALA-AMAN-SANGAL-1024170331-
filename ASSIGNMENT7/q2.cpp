#include <stdio.h>

void improvedSelectionSort(int arr[], int n) {
    int i, j, min, max, temp;
    for (i = 0; i < n/2; i++) {
        min = i;
        max = i;
        for (j = i; j < n-i; j++) {
            if (arr[j] < arr[min])
                min = j;
            if (arr[j] > arr[max])
                max = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        if (max == i)
            max = min;
        temp = arr[n-1-i];
        arr[n-1-i] = arr[max];
        arr[max] = temp;
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    improvedSelectionSort(arr, n);
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
