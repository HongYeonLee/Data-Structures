#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
#define MAX_SIZE 10

void bubble_sort(int list[], int n){
    int i, j, temp;
    for (i = n-1; i > 0; i--){
        for (j = 0; j < i; j++){
            if(list[j] > list[j+1]){
                SWAP(list[j], list[j+1], temp);
            }
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
    bubble_sort(list, n);

    //정렬된 결과 출력
    for (i = 0; i < n; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}