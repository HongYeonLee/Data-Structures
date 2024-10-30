#include <stdio.h>
#include <malloc.h>

typedef int element;

typedef struct ListNode {  // 노드를 구조체로 정의
    int coef;
    int expon;
    struct ListNode* link;
} ListNode;

//연결리스트 헤더 노드
typedef struct ListType{
    int size;
    ListNode* head;
    ListNode* tail;
} ListType;

ListType* create(){
    ListType* plist = (ListType*)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

void poly_print(ListType* plist){
    ListNode* p = plist->head;

    printf("ploynomial = ");
    for (; p; p = p->link){
        printf("%dx^%d + ", p->coef, p->expon);
    }
    printf("\n");
}

ListNode* insert_last(ListType* plist, int coef, int expon){
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));

    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;
    if(plist->tail == NULL){
        plist->head = plist->tail = temp;
    }
    else{
        plist->tail->link = temp;
        plist->tail = temp;
    }
    plist->size++;
}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3){ //list3 = list1 + list2
    ListNode* a = plist1->head;
    ListNode* b = plist2->head;
    int sum;
    while(a && b){ //a와 b가 NULL이 아니라면
        if(a->expon > b->expon){ // a의 차수 > b의 차수
            insert_last(plist3, a->coef, a->expon);
            a = a->link;
        }
        else if (a->expon == b->expon){ // a의 차수 = b의 차수
            sum = a->coef + b->coef;
            if(sum != 0){
                insert_last(plist3, sum, a->expon);
            }
            a = a->link;
            b = b->link;
        }
        else{
            insert_last(plist3, b->coef, b->expon);
            b = b->link;
        }
    }

    //a나 b중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두 결과 다항식으로 복사
    for (; a != NULL; a = a->link){
        insert_last(plist3, a->coef, a->expon);
    }

    for (; b != NULL; b = b->link){
        insert_last(plist3, b->coef, b->expon);
    }
}

int main(void) {
    ListType *list1, *list2, *list3;

    list1 = create();
    list2 = create();
    list3 = create();

    insert_last(list1, 3, 12);
    insert_last(list1, 2, 8);
    insert_last(list1, 1, 0);

    insert_last(list2, 8, 12);
    insert_last(list2, -3, 10);
    insert_last(list2, 10, 6);

    poly_print(list1);
    poly_print(list2);

    poly_add(list1, list2, list3);
    poly_print(list3);

    free(list1);
    free(list2);
    free(list3);

    return 0;
}
