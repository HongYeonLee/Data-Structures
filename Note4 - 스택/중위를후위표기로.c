#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100 //스택의 최대 크기
typedef char element;
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

int prec(char operator){
    switch(operator){
        case '(': case ')':
        return 0;
        case '+': case '-':
        return 1;
        case '*': case '/':
        return 2;
    }
    return -1;
}

void infix_to_postfix(char exp[]){ //중위 표기식 -> 후위 표기식
    char ch, top_operator;
    int len = strlen(exp);
    StayckType s;
    inint_stack(&s);
    for (int i = 0; i < len; i++){
        ch = exp[i];
        switch (ch)
        {
        case '+': case '-': case '*': case '/': //연산자인 경우
            while(!is_empty(&s) && (prec(ch) <= prec(peek(&s)))){ //스택이 비어있지 않고, 들어갈 연산자가 안에 있는 연산자보다 우선순위가 낮다면 ex) 스택에 *가 있고 +가 들어올려는 경우
                printf("%c", pop(&s));
            }
            push(&s, ch);
            break;
        case '(': //왼쪽 괄호
            push(&s, ch);
            break;
        case ')': //오른쪽 괄호
            top_operator = pop(&s);
            while(top_operator != '('){
                printf("%c", top_operator);
                top_operator = pop(&s);
            }
            break;
        default: //피연산자
            printf("%c", ch);
            break;
        }
    }
    while(!is_empty(&s)){ //스택에 남은 연산자들 출력
        printf("%c", pop(&s));
    }
}

int main(void){
    char* s = "(2+3)*4+9";
    printf("중위표기식 %s \n", s);
    printf("후위표기식 ");
    infix_to_postfix(s);
    printf("\n");
    return 0;
}