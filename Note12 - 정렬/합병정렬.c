#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int sorted[MAX_SIZE];
//i는 정렬된 왼쪽리스트에 대한 인덱스
//j는 정렬된 오른쪽 리스트에 대한 인덱스
//k는 정렬된 리스트에 대한 인덱스
void merge(int list[], int left, int mid, int right){
    int i, j, k, l;
    i = left; j = mid + 1; k = left;

    //분할 정렬된 list의 합병
    while(i <= mid && j <= right){
        if(list[i] <= list[j]){
            sorted[k++] = list[i++];
        }
        else{
            sorted[k++] = list[j++];
        }
    }

    //남아 있는 레코드의 일괄 복사
    if(i > mid){
        //j기준 배열 복사(오른쪽)
        for(l = j; l <= right; l++){
            sorted[k++] = list[l];
        }
    }
    else{
        //i기준 배열 복사 (왼쪽)
        for (l = i; l <= mid; l++){
            sorted[k++] = list[l];
        }
    }
    //배열 sorted[]의 리스트를 배열 list[]로 복사
    for(l = left; l <= right; l++){
        list[l] = sorted[l];
    }
}

void merge_sort(int list[], int left, int right){
    int mid;
    if(left < right){
        mid = (left + right)/2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}

int main(void){
    int i;
    int list[MAX_SIZE];
    int n = MAX_SIZE;
    srand(time(NULL));

    //랜덤값으로 배열 초기화
    for (i = 0; i < n; i++){
        list[i] = rand() % 100;
    }

    //삽입 정렬
    merge_sort(list, 0, n-1);

    //정렬된 결과 출력
    for (i = 0; i < n; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}