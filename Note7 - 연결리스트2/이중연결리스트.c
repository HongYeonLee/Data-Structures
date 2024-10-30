#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef int element;

typedef struct DlistNode {  // 노드를 구조체로 정의
    element data;
    struct DlistNode* llink;  // 자기 참조 구조체
    struct DlistNode* rlink;
} DlistNode;

void init(DlistNode* phead){
    phead->llink = phead;
    phead->rlink = phead;
}

void dinsert(DlistNode* before, element data){
    DlistNode* newnode = (DlistNode*)malloc(sizeof(DlistNode));
    newnode->data = data;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

void ddelete(DlistNode* head, DlistNode* removed){
    if (removed == head){
        return;
    }
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

void print_dlist(DlistNode* phead){
    DlistNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink){
        printf("<-| |%d| |->", p->data);
    }
    printf("\n");
}

int main(void){
    DlistNode* head = (DlistNode*)malloc(sizeof(DlistNode));
    init(head);
    printf("추가 단계\n");
    for (int i = 0; i < 5; i++){
        //헤더 노드의 오른쪽에 삽입
        dinsert(head, i);
        print_dlist(head);
    }
    printf("삭제 단계\n");
    for (int i = 0; i < 5; i++){
        print_dlist(head);
        ddelete(head, head->rlink);
    }
    free(head);
    return 0;
}