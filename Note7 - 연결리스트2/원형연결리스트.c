#include <stdio.h>
#include <malloc.h>

typedef int element;

typedef struct ListNode {  // 노드를 구조체로 정의
    element data;
    struct ListNode* link;  // 자기 참조 구조체
} ListNode;

ListNode* insert_first(ListNode* head, element data){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if(head == NULL){
        head = node;
        node->link = head;
    }
    else{
        node->link = head->link;
        head->link = node;
    }

    return head;
}

ListNode* insert_last(ListNode* head, element data){
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if(head == NULL){
        head = node;
        node->link = head;
    }
    else{
        node->link = head->link;
        head->link = node;
        head = node;
    }

    return head;
}

void print_list(ListNode* head){
    ListNode* p;
    if(head == NULL){
        return;
    }
    p = head->link; //시작 노드
    do {
        printf("%d->", p->data);
        p = p->link;
    }while(p != head->link);
}

int main(void){
    ListNode* head = NULL;
    
    head = insert_last(head, 20);
    head = insert_last(head, 30);
    head = insert_last(head, 40);
    head = insert_first(head, 10);
    print_list(head);
    return 0;
}