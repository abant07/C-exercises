// Amogh Bantwal
// amoghb07@uw.edu

#include "stdio.h"

void CopyAndSort(int arr[12], int sorted[12]);

int main(int argc, char* argv[]) {
    int arr1[12] = {3, 2, -5, 7, 17, 42, 6, 333, 7, 8, -8, 6};
    int arr2[12] = {0};
    CopyAndSort(arr1, arr2);

    for (int i = 0; i < 12; i++) {
        printf("%d ", arr2[i]);
    }

    return 0;
}

void CopyAndSort(int arr[12], int sorted[12]) {
    for (int i = 0; i < 12; i++) {
        sorted[i] = arr[i];
        int j = i;
        int tmp = 0;
        while (j > 0 && sorted[j] < sorted[j-1]) {
            tmp = sorted[j-1];
            sorted[j-1] = sorted[j];
            sorted[j] = tmp;
            j -= 1;
        }
    }
}