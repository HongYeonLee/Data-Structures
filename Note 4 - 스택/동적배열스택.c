#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
    element* data; //data는 포인터로 정의된다
    int capacity; //현재 크기
    int top;
}StayckType;

void init_stack(StayckType* s){
    s->top = -1;
    s->capacity = 1;
    s->data = (element*)malloc(s->capacity * sizeof(element));
}

void delete(StayckType *s){
    free(s);
}

int is_full(StayckType* s){
    return ((s->top + 1) == s->capacity);
}

int is_empty(StayckType* s){
    return s->top == -1;
}

void push(StayckType* s, element item){
    if(is_full(s)){
        s->capacity *= 2;
        s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
    }
    s->data[++s->top] = item;
}

element pop(StayckType* s){
    if(is_empty(s)){
        return 0;
    }
    return s->data[s->top--];
}

element peek(StayckType* s){
    if(is_empty(s)){
        return 0;
    }
    return s->data[s->top];
}

int main(void){
    StayckType* s;
    s = (StayckType*)malloc(sizeof(StayckType));
    init_stack(s);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    return 0;
}