// https://www.acmicpc.net/problem/2751

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);
void merge(int* arr, int* sorted, int left, int mid, int right);
void mergeSort(int* arr, int* sorted, int left, int right);

int main(){
    int* arr;
    int *sorted; 
    int len = 0;

    scanf("%d", &len);
    arr = malloc(sizeof(int)*len);
    sorted = malloc(sizeof(int)*len);

    for(int i=0; i<len; i++){
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, sorted, 0, len-1);

    for(int i=0; i<len; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int* arr, int* sorted, int left, int mid, int right) {

    int i = left;
    int j = mid+1;
    int k = left; 

    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            sorted[k] = arr[i];
            i++;
        } else {
            sorted[k] = arr[j];
            j++;
        }

        k++;
    }

    while(i <= mid){
        sorted[k] = arr[i];
        i++;
        k++;
    }
    while(j <= right){
        sorted[k] = arr[j];
        j++;
        k++;
    }

    for(int l = left; l <= right; l++){
        arr[l] = sorted[l];
    }
}

void mergeSort(int* arr, int* sorted, int left, int right) {
    if(left < right){
        int mid = (left+right)/2;

        mergeSort(arr ,sorted, left, mid);
        mergeSort(arr ,sorted, mid+1, right);

        merge(arr, sorted, left, mid, right);
    }
}