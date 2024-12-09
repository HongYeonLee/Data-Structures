#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

//gap만큼 떨어진 요소들을 삽입 정렬
//정렬의 범위는 fisrt에서 last
void inc_insertion_sort(int list[], int first, int last, int gap){
    int i, j, key;
    for (i = first + gap; i <= last; i += gap){
        key = list[i];
        for (j = i - gap; j >= first && list[j] > key; j -= gap){
            list[j + gap] = list[j];
        }
        list[j + gap] = key;
    }
}

void shell_sort(int list[], int n){
    int i, gap;
    for (gap /= 2; gap > 0; gap /= 2){
        if(gap %2 == 0){
            gap++;
        }
        //i는 시작 인덱스
        for (i = 0; i < gap; i++){
            inc_insertion_sort(list, i, n-1, gap);
        }
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
    shell_sort(list, n);

    //정렬된 결과 출력
    for (i = 0; i < n; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}
