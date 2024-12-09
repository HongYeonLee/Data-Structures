#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
#define MAX_SIZE 10

void selection_sort(int list[], int n){
    int i, j, least, temp;
    for (i = 0; i < n-1; i++){
        least = i;

        for(j = i + 1; j < n; j++){ //최솟값 탐색
            if(list[j] < list[least]){
                least = j;
            }
        }
        SWAP(list[i], list[least], temp); //값 교환
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

    //선택정렬
    selection_sort(list, n);

    //정렬된 결과 출력
    for (i = 0; i < n; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}