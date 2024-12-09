#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_VERTICES 100

typedef struct GraphNode{
    int vertex;
    struct GraphNode* link;
}GraphNode;

typedef struct GraphType{
    int n; //정점의 개수
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

//그래프 초기화
void init(GraphType* g){
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++){
        g->adj_list[v] = NULL;
    }
}

//정점 삽입 연산
void insert_vertex(GraphType* g, int v){
    if(((g->n) + 1) > MAX_VERTICES){
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

#define MAX_STACK_SIZE 100 //스택의 최대 크기
typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
}StayckType;

//스택 초기화 함수
void inint_stack(StayckType* s){
    s->top = -1;
}

//공백 검출 함수
int is_empty(StayckType* s){
    return (s->top == -1);
}

//포화 상태 검출 함수
int is_full(StayckType* s){
    return (s->top == (MAX_STACK_SIZE - 1));
}

//삽입 함수
void push(StayckType* s, element item){
    if(is_full(s)){
        return;
    }
    else{
        s->data[++s->top] = item;
    }
}

//삭제 함수
element pop(StayckType* s){
    if(is_empty(s)){
        return 0;
    }
    else{
        return s->data[s->top--];
    }
}

element peek(StayckType* s){
    if(is_empty(s)){
        return 0;
    }
    return s->data[s->top];
}

int topo_sort(GraphType* g){
    int i;
    StayckType s;
    GraphNode* node;

    //모든 정점의 진입 차수를 계산
    int* in_degree = (int*)malloc(g->n * sizeof(int));
    for (i = 0; i < g->n; i++){ //초기화
        in_degree[i] = 0;
    }
    for (i = 0; i < g -> n; i++){
        GraphNode* node = g->adj_list[i]; //정점 i에서 나오는 간선들
        while(node != NULL){
            in_degree[node->vertex]++;
            node = node->link;
        }
    }

    //진입 차수가 0인 정점을 스택에 삽입
    inint_stack(&s);
    for (i = 0; i < g->n; i++){
        if(in_degree[i] == 0){
            push(&s, i);
        }
    }   
    //위상 순서를 생성
    while(!is_empty(&s)){
        int w;
        w = pop(&s);
        printf("정점 %d ->", w); //정점 출력
        node = g->adj_list[w]; //각 정점의 진입 차수를 변경
        while(node != NULL){
            int u = node->vertex;
            in_degree[u]--;
            if(in_degree[u] == 0){
                push(&s, u);
            }
            node = node->link;
        }
    }

    free(in_degree);
    printf("\n");
    return (i == g->n); //반환값이 1이면 성공, 0이면 실패
}

int main(void){
    GraphType g;
    init(&g);
    insert_vertex(&g, 0);
    insert_vertex(&g, 1);
    insert_vertex(&g, 2);
    insert_vertex(&g, 3);
    insert_vertex(&g, 4);
    insert_vertex(&g, 5);

    //정점 0의 인접리스트 생성
    insert_edge(&g, 0, 2);
    insert_edge(&g, 0, 3);

    //정점 1의 인접리스트 생성
    insert_edge(&g, 1, 3);
    insert_edge(&g, 1, 4);

    //정점 2의 인접리스트 생성
    insert_edge(&g, 2, 3);
    insert_edge(&g, 2, 5);

    //정점 3의 인접리스트 생성
    insert_edge(&g, 3, 5);
    
    //정점 4의 인접리스트 생성
    insert_edge(&g, 4, 5);

    //위상 정렬
    topo_sort(&g);
    return 0;
}