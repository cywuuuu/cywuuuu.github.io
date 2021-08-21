#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp = *a; 
    *a = *b;
    *b = tmp;
}

void quick(int k[], int left, int right) {
    int i, j;
    int pivot;
    if (left < right) {
        i = left; j = right + 1;
        pivot = k[left];
        while (1) {
            while (k[++i]<pivot && i != right) ;
            while (k[--j]>pivot && j != left) ;
            if (i < j) swap(k+i,k+j);
            else break;
        }
        swap(k+left,k+j);
    }
}

int arr[] = {57, 11, 12, -23, 76, 1901, 20, 96, -38, 0};

int main()
{
    quick(arr, 0, 9);
    for (int i = 0; i < 10;i++) printf("%d ", arr[i]);
    return 0;
}