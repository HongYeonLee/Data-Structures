#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
    int is_thread; //만약 오른쪽 링크가 스레이면 true;
} TreeNode;

TreeNode* find_successor(TreeNode* p){
    //q는 p의 오른쪽 포인터
    TreeNode* q = p->right;
    //만약 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인터 반환
    if(q == NULL || q->is_thread == TRUE){
        return q; //그러니까 즉 NULL 또는 중위후석자 노드 반환
    }
    //만약 오른쪽 포인터가 자식이면 다시 가장 왼쪽 노드로 이동
    while(q->left != NULL){
        q = q->left;
    }
    return q;
}

void thread_inorder(TreeNode* t){
    TreeNode* q;
    q = t;
    //가장 왼쪽 노드로 간다
    while(q->left){
        q = q->left; 
    }
    do{
        printf("%d ", q->data);
        q = find_successor(q);
    }while(q);
}