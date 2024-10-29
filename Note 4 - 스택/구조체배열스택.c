#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100 //스택의 최대 크기
typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
}StayckType;

//스택 초기화 함수
void inint_stack(StayckType* s){
    s->top = -1;
}

//공백 검출 함수
int is_empty(StayckType* s){
    return (s->top == -1);
}

//포화 상태 검출 함수

int is_full(StayckType* s){
    return (s->top == (MAX_STACK_SIZE - 1));
}

//삽입 함수
void push(StayckType* s, element item){
    if(is_full(s)){
        return;
    }
    else{
        s->data[++s->top] = item;
    }
}

//삭제 함수
element pop(StayckType* s){
    if(is_empty(s)){
        return 0;
    }
    else{
        return s->data[s->top--];
    }
}

element peek(StayckType* s){
    if(is_empty(s)){
        return 0;
    }
    return s->data[s->top];
}

int main(void){
    StayckType s;
    inint_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
}

