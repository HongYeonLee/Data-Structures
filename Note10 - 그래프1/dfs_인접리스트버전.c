#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICS 50
#define TRUE 1
#define FALSE 0

int visited[MAX_VERTICS];

typedef struct GraphNode{
    int vertex;
    struct GraphNode* link;
}GraphNode;

typedef struct GraphType{
    int n; //정점의 개수
    GraphNode* adj_list[MAX_VERTICS];
} GraphType;

//그래프 초기화
void init(GraphType* g){
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICS; v++){
        g->adj_list[v] = NULL;
        visited[v] = FALSE;
    }
}

//정점 삽입 연산
void insert_vertext(GraphType* g, int v){
    if(((g->n) + 1) > MAX_VERTICS){
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

//간선 삽입 연산, v를 u의 인접 리스트에 삽입한다
void insert_edge(GraphType* g, int u, int v){
    GraphNode* node;
    if(u >= g->n || v >= g->n){
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }

    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

//출력
void print_adj_list(GraphType* g){
    for (int i = 0; i < g->n; i++){
        GraphNode* p = g->adj_list[i];
        printf("정점 %d의 인접 리스트 ", i);
        while(p != NULL){
            printf("-> %d ", p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}

void dfs_list(GraphType* g, int v){
    GraphNode* w;
    visited[v] = TRUE;
    printf("정점 %d -> ", v);
    for(w = g->adj_list[v]; w; w = w->link){
        if(!visited[w->vertex]){
            dfs_list(g, w->vertex);
        }
    }
}

int main(){
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for(int i = 0; i < 4; i++){
        insert_vertext(g, i);
    }

    insert_edge(g, 0, 1);
    insert_edge(g, 1, 0);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 0);
    insert_edge(g, 0, 3);
    insert_edge(g, 3, 0);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 3, 2);
    dfs_list(g, 0);
    free(g);
    return 0;
}