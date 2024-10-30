#include <stdio.h>
#include <malloc.h>

typedef int element;

typedef struct StackNode {  // 노드를 구조체로 정의
    element data;
    struct StackNode* link;  // 자기 참조 구조체
} StackNode;

typedef struct{
    StackNode* top;
}LinkedStackType;

void init(LinkedStackType* s){
    s->top = NULL;
}

int is_empty(LinkedStackType* s){
    return s->top == NULL;
}

int is_full(LinkedStackType* s){
    return 0;
}

void push(LinkedStackType* s, element item){
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    temp->data = item;
    temp->link = s->top;
    s->top = temp;
}

element pop(LinkedStackType* s){
    if(is_empty(s)){
        return -1;
    }
    else{
        StackNode* temp = s->top; //삭제할 대상 잡고 있기
        element data = temp->data;
        s->top = s->top->link;
        free(temp);
        return data;
    }
}

void print_stack(LinkedStackType* s){
    for (StackNode* p = s->top; p != NULL; p = p->link){
        printf("%d->", p->data);
    }
    printf("NULL \n");
}

int main(void) {
    LinkedStackType s;
    init(&s);
    push(&s, 1);
    print_stack(&s);
    push(&s, 2);
    print_stack(&s);
    push(&s, 3);
    print_stack(&s);

    pop(&s);
    print_stack(&s);
    pop(&s);
    print_stack(&s);
    pop(&s);
    print_stack(&s);

    return 0;
}
