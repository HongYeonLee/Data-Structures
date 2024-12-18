#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 100000

typedef struct GraphType{
    int n; //정점의 개수
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES]; //시작 정점으로부터의 최단 경로 거리
int found[MAX_VERTICES]; //방문한 정점 표시

int choose(int distance[], int n, int found[]){
    int i, min, minpos;
    min = INT_MAX;
    minpos = -1;
    for (i = 0; i < n; i++){
        if(distance[i] < min && !found[i]){
            min = distance[i];
            minpos = i;
        }
    }
    return minpos;
}

void shortest_path(GraphType* g, int start){
    int i, u, w;
    for (i = 0; i < g->n; i++){
        distance[i] = g->weight[start][i];
        found[i] = FALSE;
    }
    found[start] = TRUE; //시작 정점 방문 표시
    distance[start] = 0;
    for (i = 0; i < g->n - 1; i++){
        print_status(g); //교재 참고
        u = choose(distance, g->n, found);
        found[u] = TRUE;
        for (w = 0; w < g->n; w++){
            if(!found[w]){
                if(distance[u] + g->weight[u][w] < distance[w]){
                    distance[w] = distance[u] + g->weight[u][w];
                }
            }
        }
    }
}

int main(void){
    GraphType g = {7,
    {{0, 7, INF, INF, 3, 10, INF},
    {7, 0, 4, 10, 2, 6, INF},
    {INF, 4, 0, 2, INF, INF, INF},
    {INF, 10, 2, 0, 11, 9, 4},
    {3, 2, INF, 11, 0, INF, 5},
    {10, 6, INF, 9, INF, 0, INF},
    {INF, INF, INF, 4, 5, INF, 0}}
    };
    shortest_path(&g, 0);
    return 0;
}