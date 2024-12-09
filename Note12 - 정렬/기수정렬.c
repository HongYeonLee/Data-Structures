#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define MAX_QUEUE_SIZE 5
#define BUCKETS 10
#define DIGITS 4

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

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

void radix_sort(int list[], int n){
    int i, b, d, factor = 1;
    QueueType queues[BUCKETS];

    for (b = 0; b < BUCKETS; b++){
        init_queue(&queues[b]); //큐들의 초기화
    }
    for (d = 0; d <DIGITS; d++){
        for (i = 0; i < n; i++){ //데이터들을 자리수에 따라 큐에 입력
            enqueue(&queues[(list[i]/factor)%10], list[i]);
        }

        for(b = i = 0; b <BUCKETS; b++){ //버켓에서 꺼내에서 list로 합친다
            while(!is_empty(&queues[b])){
                list[i++] = dequeue(&queues[b]);
            }
        }
        factor *= 10; //그 다음 자리수로 간다
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
    radix_sort(list, n);

    //정렬된 결과 출력
    for (i = 0; i < n; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}



