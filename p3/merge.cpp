#include <stdio.h>

void merge(int *arr, int *leftArray, int ls, int *rightArray, int rs);

void mergesort(int *arr, int n) {
    if (n < 2) {
        return;
    }

    int ls = n / 2;
    int rs = n - ls;
    int i;

    int leftArray[ls];
    int rightArray[rs];

    for (i = 0; i < ls; i++) {
        leftArray[i] = arr[i];
    }
    for (i = ls; i < n; i++) {
        rightArray[i - ls] = arr[i];
    }

    mergesort(leftArray, ls);
    mergesort(rightArray, rs);
    merge(arr, leftArray, ls, rightArray, rs);
}

void merge(int *arr, int *leftArray, int ls, int *rightArray, int rs) {
    int i = 0, j = 0, k = 0;
    while (i < ls && j < rs) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < ls) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < rs) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

int main() {
    int x[8], i;
    printf("Enter the elements in the array:\n");
    for (i = 0; i < 8; i++) {
        scanf("%d", &x[i]);
    }

    printf("Data before sorting:\n");
    for (i = 0; i < 8; i++) {
        printf("%d\t", x[i]);
    }
    printf("\n");

    mergesort(x, 8);

    printf("Data after sorting:\n");
    for (i = 0; i < 8; i++) {
        printf("%d\t", x[i]);
    }
    printf("\n");

    return 0;
}
