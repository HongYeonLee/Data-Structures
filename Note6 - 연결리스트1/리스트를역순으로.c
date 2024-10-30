#include <stdio.h>
#include <malloc.h>

typedef int element;

typedef struct ListNode {  // 노드를 구조체로 정의
    element data;
    struct ListNode* link;  // 자기 참조 구조체
} ListNode;

ListNode* insert_first(ListNode* head, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

// 노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

ListNode* delete_first(ListNode* head) {
    ListNode* removed;
    if (head == NULL) {
        return NULL;
    }
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

// pre가 가리키는 노드의 다음 노드를 삭제한다
ListNode* delete(ListNode* head, ListNode* pre) {
    ListNode* removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(ListNode* head) {
    for (ListNode* p = head; p != NULL; p = p->link) {
        printf("%d->", p->data);
    }
    printf("\n");
}

ListNode* reverse(ListNode* head){
    //순회 포인터로 p, q, r사용
    ListNode *p, *q, *r;
    p = head;
    q = NULL;
    while(p != NULL){
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
}

int main(void) {
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;
    
    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    print_list(head1);

    head2 = reverse(head1);
    print_list(head2);
    return 0;
}
