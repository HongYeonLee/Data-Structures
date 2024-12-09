#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10


void insertion_sort(int list[], int n){
    int i, j, key;
    for (i = 1; i < n; i++){
        key = list[i];
        for(j = i - 1; j >= 0 && list[j] > key; j--){
            list[j + 1] = list[j];
        }
        list[j + 1] = key;
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
    insertion_sort(list, n);

    //정렬된 결과 출력
    for (i = 0; i < n; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}