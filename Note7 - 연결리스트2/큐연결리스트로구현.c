#include <stdio.h>
#include <malloc.h>

typedef int element;

typedef struct QueueNode {  // 노드를 구조체로 정의
    element data;
    struct StackNode* link;  // 자기 참조 구조체
} QueueNode;

typedef struct{
    QueueNode *front, *rear;
}LinkedQueueType;

void init(LinkedQueueType* q){
    q->front = q->rear = NULL;
}

int is_empty(LinkedQueueType* q){
    return q->front == q->rear;
}

int is_full(LinkedQueueType* q){
    return 0;
}

void enqueue(LinkedQueueType* q, element item){
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = item;
    temp->link = NULL;
    if(is_empty(q)){
        q->front = temp;
        q->rear = temp;
    }
    else{
        q->rear->link = temp;
        q->rear = temp;
    }
}

element dequeue(LinkedQueueType* q){
    QueueNode* temp = q->front; //삭제할 대상 잡고 있기
    if(is_empty(q)){
        return -1;
    }
    else{
        element data = temp->data;
        q->front = q->front->link;
        if(q->front == NULL){
            q->rear == NULL;
        }
        free(temp);
        return data;
    }
}
