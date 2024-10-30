#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} DequeType;

void init_queue(DequeType* q){
    q->front = q->rear = 0;
}

int is_empty(DequeType* q){
    return q->front == q->rear;
}

int is_full(DequeType* q){
    return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}

void deque_print(DequeType* q){
    printf("Deque(front = %d rear = %d) = ", q->front, q->rear);
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
void add_rear(DequeType* q, element item){
    if(!is_full(q)){
        q->rear = (q->rear + 1)%MAX_QUEUE_SIZE;
        q->data[q->rear] = item;
    }
}

//삭제함수
element delete_front(DequeType* q){
    if(!is_empty(q)){
        q->front = (q->front + 1)%MAX_QUEUE_SIZE;
    }
    return q->data[q->front];
}

element get_front(DequeType* q){
    if(!is_empty(q)){
        printf("비어있음");
        return -1;
    }
    return q->data[(q->front + 1)%MAX_QUEUE_SIZE];
}

void add_front(DequeType* q, element item){
    if(!is_full(q)){
        q->data[q->front] = item;
        q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; 
    }
}

element delete_rear(DequeType* q){
    int prev = q->rear;
    if(!is_empty(q)){
        q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    }
    return q->data[prev];
}

element get_rear(DequeType* q){
    if(is_empty(q)){
        return -1;
    }
    return q->data[q->rear];
}

int main(void){
    DequeType deque;

    init_queue(&deque);
    for (int i = 0; i < 3; i++){
        add_front(&deque, i);
        deque_print(&deque);
    }

    for (int i = 0; i < 3; i++){
        delete_rear(&deque);
        deque_print(&deque);
    }
    return 0;
}