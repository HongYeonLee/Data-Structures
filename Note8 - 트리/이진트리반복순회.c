#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define SIZE 100

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

int top = -1;
TreeNode* stack[SIZE];

void push(TreeNode* p){
    if(top < SIZE - 1){
        stack[++top] = p;
    }
}

TreeNode* pop(){
    TreeNode* p = NULL;
    if(top >= 0){
        p = stack[top--];
    }
    return p;
}

void inoder_iter(TreeNode* root){
    while(1){
        for (; root; root = root->left){ // 15 -> 4 -> 1 -> 20 -> 16 -> 25
            push(root);
        }
        root = pop(); // 1 -> 4 -> 15 -> 16 -> 20
        if(!root){ //root가 NULL인 경우
            break;
        }
        printf("[%d] ", root->data);
        root = root ->right; //NULL -> NULL -> 20 -> NULL -> 25
    }
}

int main(void){
    printf("중위순환");
    inoder_iter(root);
    printf("\n");
    return 0;
}