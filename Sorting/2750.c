// https://www.acmicpc.net/problem/2750

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* arr, int len);
void insertionSort(int* arr, int len);
void quickSort(int* arr, int len, int left, int right);
int partition(int* arr, int len, int left, int right);
int getMedianOfThree(int* arr, int len, int left, int right);
void swap(int* a, int* b);

int main(){
    int* arr;
    int len = 0;

    scanf("%d", &len);
    arr = malloc(sizeof(int)*len);

    for(int i=0; i<len; i++){
        scanf("%d", &arr[i]);
    }

    // bubbleSort(arr, len);
    // insertionSort(arr,len);
    quickSort(arr, len, 0, len-1);

    for(int i=0; i<len; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}

// Bubble Sort
void bubbleSort(int* arr, int len){
    int isSorted = 1; // 0=정렬 미완료, 1=정렬 완료
    for(int i=0; i<len-1; i++){
        for(int j=0; j<len-1-i; j++){
            if(arr[j] > arr[j+1]){
                isSorted = 0;
                swap(&arr[j], &arr[j+1]);
            }
        }
    if(isSorted) break;
    }
}

// Insertion Sort
void insertionSort(int* arr, int len){
    for(int i=1; i<len; i++){
        if(arr[i-1] < arr[i]) continue;
        int key = arr[i];

        for(int j=0; j<i; j++){
            if(arr[j] > key){
                for(int k=i; k>j; k--){
                    arr[k] = arr[k-1];
                }
                arr[j] = key;
                break;
            }
        }
    }
}

// Quick Sort
void quickSort(int* arr, int len, int left, int right){
    if(left < right){
        int index = partition(arr, len, left, right);

        quickSort(arr, len, left, index-1);
        quickSort(arr, len, index+1, right);
    }   
}

/*
1. pivot 선정: 중앙값(처음, 중간, 끝)
2. pivot을 맨 왼쪽 요소로 이동
3. 왼쪽에서 오른쪽으로 이동하면서 pivot보다 큰거나 같은 요소를 찾을 때 까지 이동
4. 오른쪽에서 왼쪽으로 이동하면서 pivot보다 작거나 같은 요소를 찾을 때 까지 이동
5. 3,4 번에서 조건을 충족하는 요소를 찾고 둘의 위치가 서로 지나치지 않았다면 교환
6. 둘의 위치가 서로 지나치거나 만났다면 모든 요소를 검사했고 정렬이 완료되었다는 의미이므로 피벗의 위치와 지나친 위치와 교환
*/
int partition(int* arr, int len, int left, int right){
    int pivotIdx = getMedianOfThree(arr, len, left, right);

    if(pivotIdx != left) swap(&arr[left], &arr[pivotIdx]);
    pivotIdx = left;
    int pivotValue = arr[pivotIdx];
    left++;

    while(left <= right){

        while(arr[left] <= pivotValue && left < right) left++;
        while(arr[right] >= pivotValue && left <= right) right--;

        if(left < right) swap(&arr[left], &arr[right]);
        else break;
    }

    swap(&arr[pivotIdx], &arr[right]);

    return right;
}

int getMedianOfThree(int* arr, int len, int left, int right) {
    int a = left;
    int b = (left+right)/2;
    int c = right;

    int l = arr[a], m = arr[b], r = arr[c];

    if ((l <= m && m <= r) || (r <= m && m <= l)) return b;
    else if ((m <= l && l <= r) || (r <= l && l <= m)) return a;
    else return c;
}


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}