#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICS 50
#define MAX_QUEUE_SIZE 5
#define TRUE 1
#define FALSE 0

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

typedef struct GraphType{
    int n; //정점의 개수
    int adj_mat[MAX_VERTICS][MAX_VERTICS];
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

void bfs_mat(GraphType* g, int v){
    int w;
    QueueType q;
    init_queue(&q); //큐 초기화
    visited[v] = TRUE;
    printf("%d 방문 -> ", v);
    enqueue(&q, v);
    while(!is_empty(&q)){
        v = dequeue(&q); //쿠의 정점 추출
        for(w = 0; w < g->n; w++){ //인접 정점 탐색
            if(g->adj_mat[v][w] && !visited[w]){
                visited[w] = TRUE;
                printf("%d 방문 -> ", w);
                enqueue(&q, w);
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
    bfs_mat(g, 0);
    printf("\n");
    free(g);
    return 0;
}