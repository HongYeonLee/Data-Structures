#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

//노드의 개수 구하기
int get_node_count(TreeNode* node){
    int count = 0;
    if(node != NULL){
        count = 1 + get_node_count(node->left) + get_node_count(node->right);
    }
    return count;
}

//트리의 높이 구하기
int get_height(TreeNode *node){
    int height = 0;
    if(node != NULL){
        height = 1 + fmax(get_height(node->left), get_height(node->right));
    }
    return height;
}

//단말 노드의 개수
int get_leaf_count(TreeNode* node){
    int count = 0;
    if(node != NULL){
        if(node->left == NULL && node->right == NULL){
            return 1;
        }
        else{
            count = get_leaf_count(node->left) + get_leaf_count(node->right);
        }
    }
    return count;
}

int main(void){
    // 예시 트리 구성
    //       8
    //     /    \
    //    5      9
    //   / \       \
    //  1   4       7
    TreeNode n1 = {1, NULL, NULL};
    TreeNode n2 = {4, NULL, NULL};
    TreeNode n3 = {7, NULL, NULL};
    TreeNode n4 = {5, &n1, &n2};
    TreeNode n5 = {9, NULL, &n3};
    TreeNode root = {8, &n4, &n5};

    printf("노드의 개수: %d\n", get_node_count(&root));
    printf("트리의 높이: %d\n", get_height(&root));
    printf("단말 노드의 개수: %d\n", get_leaf_count(&root));

    return 0;
}
