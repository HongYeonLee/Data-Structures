#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5
#define MAX_VERTICS 50
#define TRUE 1
#define FALSE 0

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

typedef struct GraphNode{
    int vertex;
    struct GraphNode* link;
}GraphNode;

typedef struct GraphType{
    int n; //정점의 개수
    GraphNode* adj_list[MAX_VERTICS];
} GraphType;

int visited[MAX_VERTICS];

void init_queue(QueueType* q){
    q->front = q->rear = 0;
}

int is_empty(QueueType* q){
    return q->front == q->rear;
}

int is_full(QueueType* q){
    return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}

void queue_print(QueueType* q){
    printf("Queue(front = %d rear = %d) = ", q->front, q->rear);
    if(!is_empty(q)){
        int i = q->front;
        do{
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if(i == q->rear){
                break;
            }
        } while(i != q->front);
    }
    printf("\n");
}

//삽입함수
void enqueue(QueueType* q, element item){
    if(!is_full(q)){
        q->rear = (q->rear + 1)%MAX_QUEUE_SIZE;
        q->data[q->rear] = item;
    }
}

//삭제함수
element dequeue(QueueType* q){
    if(!is_empty(q)){
        q->front = (q->front + 1)%MAX_QUEUE_SIZE;
    }
    return q->data[q->front];
}

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
void insert_vertex(GraphType* g, int v){
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

void bfs_list(GraphType* g, int v){
    GraphNode* w;
    QueueType q;

    init_queue(&q); //큐 초기화
    visited[v] = TRUE; //정점 v 방문 표시
    printf("%d 방문 -> ", v);
    enqueue(&q, v); //시작 정점을 큐에 저장
    while(!is_empty(&q)){
        v = dequeue(&q); //큐에 저장된 정점 선택
        for (w = g->adj_list[v]; w; w = w->link){ //인접 정점 탐색
            if(!visited[w->vertex]){
                visited[w->vertex] = TRUE;
                printf("%d 방문 -> ", w->vertex);
                enqueue(&q, w->vertex);
            }
        }
    }
}

int main(void){
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for (int i = 0; i < 6; i++){
        insert_vertex(g, i);
    }
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 0, 4);
    insert_edge(g, 4, 5);
    insert_edge(g, 1, 5);
    insert_edge(g, 2, 5);
    insert_edge(g, 3, 5);

    printf("너비 우선 탐색\n");
    bfs_list(g, 0);
    printf("\n");
    free(g);
    return 0;
    return 0;
}