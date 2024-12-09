#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICS 50
#define TRUE 1
#define FALSE 0

int visited[MAX_VERTICS];

typedef struct GraphType{
    int n; //정점의 개수
    int adj_mat[MAX_VERTICS][MAX_VERTICS];
} GraphType;

//그래프 초기화
void init(GraphType* g){
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICS; r++){
        for (c = 0; c < MAX_VERTICS; c++){
            g->adj_mat[r][c] = 0;
            visited[r] = FALSE;
        }
    }
}

//정점 삽입 연산
void insert_vertex(GraphType* g, int v){
    if((g->n) + 1 > MAX_VERTICS){
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

//간선 삽입 연산
void insert_edge(GraphType* g, int start, int end){
    if(start >= g->n || end >= g->n){
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

//출력
void print_adj_mat(GraphType* g){
    int r, c;
    for (r = 0; r < g->n; r++){
        for (c = 0; c < g->n; c++){
            printf("%d ", g->adj_mat[r][c]);
        }
        printf("\n");
    }
}

void dfs_mat(GraphType* g, int v){
    int w;
    visited[v] = TRUE;
    printf("정점 %d -> ", v);
    for(w = 0; w < g->n; w++){
        if(g->adj_mat[v][w] && !visited[w]){
            dfs_mat(g, w);
        }
    }
}

void main(){
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);

    for(int i = 0; i < 4; i++){
        insert_vertex(g, i);
    }

    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);
    
    printf("깊이 우선 탐색\n");
    dfs_mat(g, 0);
    printf("\n");
    free(g);
    return;
}

