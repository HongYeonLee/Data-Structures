#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int partition(int list[], int left, int right){
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];
    do{
        do{
            low++;
        }while(low <= right && list[low] < pivot);
        
        do{
            high--;
        }while(high >= left && list[high] > pivot);

        if(low < high){
            SWAP(list[low], list[high], temp);
        }
    }while(low < high);
    SWAP(list[left], list[high], temp); //list[left]는 피봇값
    return high;
}

void quick_sort(int list[], int left, int right){
    if(left < right){
        int q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
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
    quick_sort(list, 0, n-1);

    //정렬된 결과 출력
    for (i = 0; i < n; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}