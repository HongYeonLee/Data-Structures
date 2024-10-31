#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_QUEUE_SIZE 100

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

//     15
//   /    \
//  4     20
// /    /    \
//1   16     25

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode* root = &n6;

typedef TreeNode* element;
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

void level_order(TreeNode* ptr){
    QueueType q;
    init_queue(&q);

    if(ptr == NULL){
        return;
    }
    enqueue(&q, ptr); //루트 노드 넣기
    while(!is_empty(&q)){
        ptr = dequeue(&q);
        printf("[%d]", ptr->data);
        if(ptr->left){
            enqueue(&q, ptr->left);
        }
        if(ptr->right){
            enqueue(&q, ptr->right);
        }
    }
}

int main(void){
    printf("레벨 순회 = ");
    level_order(root);
    printf("\n");
    return 0;
}