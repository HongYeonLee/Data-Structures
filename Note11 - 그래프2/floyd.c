#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 100000

int A[MAX_VERTICES][MAX_VERTICES];

typedef struct GraphType{
    int n; //정점의 개수
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void printA(GraphType* g) {
    printf("================================\n");
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            if (A[i][j] == INF) {
                printf("%4s ", "INF"); // 경로가 없는 경우 INF로 출력
            } else {
                printf("%4d ", A[i][j]); // 경로가 있는 경우 거리 출력
            }
        }
        printf("\n");
    }
    printf("================================\n");
}

void floyd(GraphType* g){
    int i, j, k;
    for (i = 0; i < g->n; i++){
        for (j = 0; j < g->n; j++){
            A[i][j] = g->weight[i][j];
        }
    }
    printA(g);

    for (k = 0; k < g->n; k++){
        for (i = 0; i < g->n; i++){
            for (j = 0; j < g->n; j++){
                if(A[i][k] + A[k][j] < A[i][j]){
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }
        printA(g);
    }
}

int main(void){
    GraphType g = {7,
    {{0, 7, INF, INF, 3, 10, INF},
    {7, 0, 4, 10, 2, 6, INF},
    {INF, 4, 0, 2, INF, INF, INF},
    {INF, 10, 2, 0, 11, 9, 4},
    {3, 2, INF, 11, 0, 13, 5},
    {10, 6, INF, 9, 13, 0, INF},
    {INF, INF, INF, 4, 5, INF, 0}}
    };
    floyd(&g);
    return 0;
}