#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
    int key;
    struct TreeNode *left, *right;
} TreeNode;

//반복적인 탐색 함수
TreeNode* search_iter(TreeNode* node, int key){
    while(node != NULL){
        if(key == node->key){
            return node;
        }
        else if (key < node->key){
            node = node->left;
        }
        else{
            node = node->right;
        }
    }
    return NULL;
}

//순환적인 탐색함수
TreeNode* search_recur(TreeNode* node, int key){
    if(node == NULL){
        return NULL;
    }
    if(key == node->key){
        return node;
    }
    else if(key < node->key){
        return search_recur(node->left, key);
    }
    else{
        return search_recur(node->right, key);
    }
}

TreeNode* new_node(int item){
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

//삽입 연산
TreeNode* insert_node(TreeNode* node, int key){
    //트리가 공백이면 새로운 노드를 반환한다
    if(node == NULL){
        return new_node(key);
    }
    //그렇지 않으면 순환적으로 트리를 내려간다.
    if(key < node->key){
        node->left = insert_node(node->left, key);
    }
    else if(key > node->key){
        node->right = insert_node(node->right, key);
    }
    return node;
}

TreeNode* min_value_node(TreeNode* node){
    TreeNode* current = node;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}

//이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고 새로운 루트 노드를 반환한다.
TreeNode* delete_node(TreeNode* root, int key){
    if(root == NULL){
        return root;
    }
    if(key < root->key){ // 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
        root->left = delete_node(root->left, key);
    }
    else if (key > root->key){ //만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
        root->right = delete_node(root->right, key);
    }
    else{//키와 노드의 값이 같은 경우, 즉 삭제할 노드를 찾을 경우
        if(root->left == NULL){ //삭제할 노드가 단말노드이거나 자식이 오른쪽 서브트리만 있는 경우
            TreeNode* temp = root->right; //삭제할 노드의 오른쪽 자식을 잡아둔다
            free(root);
            return temp;
        }
        else if(root->right == NULL){//삭제할 노드가 왼쪽 서브트리만 있는 경우
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        //삭제할 노드가 양쪽 서브트리가 전부 있는 경우
        TreeNode* temp = min_value_node(root->right); //오른쪽 서브트리에서 가장 작은 값은 가진 노드 찾아오기 (가장 왼쪽에 있는 노드)
        root->key = temp->key; //삭제할 노드의 키 값에 방금 찾은 오른쪽 서브트리에서 가장 작은 값을 쓰고
        root->right = delete_node(root->right, temp->key); //오른쪽 서브트리에서 해당 키 값을 가진 노드를 찾아 삭제한다
    }
    return root;
}

void inorder(TreeNode* root){ //중위순회
    if(root){
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main(void){
    TreeNode* root = NULL;
    TreeNode* tmp = NULL;
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 10);
    root = insert_node(root, 40);
    root = insert_node(root, 50);
    root = insert_node(root, 60);

    printf("이진 탐색 트리 중위 순회 결과\n");
    inorder(root);
    printf("\n");
    if(search_recur(root, 50) != NULL){
        printf("이진 탐색 트리에서 50을 발견함 \n");
    }
    else{
        printf("실패\n");
    }
    return 0;
}