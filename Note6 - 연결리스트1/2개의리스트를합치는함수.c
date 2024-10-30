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

ListNode* concat_list(ListNode* head1, ListNode* head2){
    if(head1 == NULL) {
        return head2;
    }
    else if(head2 == NULL){
        return head1;
    }
    else{
        ListNode* p = head1;
        while(p->link != NULL){
            p = p->link;
        }
        p->link = head2;
        return head1;
    }
    
}
int main(void) {
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;
    
    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    print_list(head1);

    head2 = insert_first(head2, 40);
    head2 = insert_first(head2, 50);
    print_list(head2);

    head1 = concat_list(head1, head2);
    print_list(head1);
    
    return 0;
}
