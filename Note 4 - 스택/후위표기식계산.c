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

int eval(char exp[]){
    int operand1, operand2, value;
    int len = strlen(exp);
    char ch;
    StayckType s;
    inint_stack(&s);

    for (int i = 0; i < len; i++){
        ch = exp[i];
        if(ch != '+' && ch != '-' && ch != '*' && ch != '/'){ //연산자가 아니라면, 즉 피연산라면
            value = ch - '0';
            push(&s, value);
        }
        else{//연산자라면
            operand2 = pop(&s);
            operand1 = pop(&s);
            switch (ch)
            {
            case '+':
                push(&s, operand1 + operand2);
                break;
            
            case '-':
                push(&s, operand1 - operand2);
                break;
            
            case '*':
                push(&s, operand1 * operand2);
                break;
            
            case '/':
                push(&s, operand1 / operand2);
                break;
            }
        }
    }
    return pop(&s);
}

int main(void){
    int result;
    printf("후위표기식은 82/3-32*+\n");
    result = eval("82/3-32*+");
    printf("결과값은 %d\n", result);
    return 0;
}