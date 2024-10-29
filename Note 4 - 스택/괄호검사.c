#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int check_matching(const char* in){
    StayckType s;
    char ch, open_ch;
    int n = strlen(in);
    inint_stack(&s);

    for (int i = 0; i < n; i++){
        ch = in[i];
        switch (ch)
        {
        case '(': case '[': case '{':
            push(&s, ch);
            break;
        case ')': case ']': case '}':
            if(is_empty(&s)){
                return 0;
            }
            else{
                open_ch = pop(&s);
                if( (open_ch == '(' && ch != ')') ||
                    (open_ch == '[' && ch != ']') ||
                    (open_ch == '{' && ch != '}'))
                    return 0;
            }
            break;
        }
    }

    if(!is_empty(&s)){
        return 0;
    }
    return 1;
}

int main(void){
    char* p = "{ A[(i+1)]=0; }";
    if(check_matching(p) == 1){
        printf("%s 괄호검사성공\n", p);
    }
    else{
        printf("%s, 괄호검사실패\n", p);
    }
    return 0;
}