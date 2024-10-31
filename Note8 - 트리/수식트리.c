#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

//      +
//    /    \
//   *      20
//  / \     /  \
// 1   4   16   25

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, NULL, NULL};
TreeNode n3 = {'*', &n1, &n2};
TreeNode n4 = {16, NULL, NULL};
TreeNode n5 = {25, NULL, NULL};
TreeNode n6 = {'+', &n4, &n5};
TreeNode n7 = {'+', &n3, &n6};
TreeNode* expression = &n7;

int evaluate(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    if(root -> left == NULL && root->right == NULL){
        return root->data;
    }
    else {
        int operand1 = evaluate(root->left);
        int operand2 = evaluate(root->right);
        printf("%d %c %d을 계산합니다.\n", operand1, root->data, operand2);
        switch (root->data)
        {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        }
    }
    return 0;
}

int main(void){
    printf("수식의 값은 %d입니다\n", evaluate(expression));
    return 0;
}