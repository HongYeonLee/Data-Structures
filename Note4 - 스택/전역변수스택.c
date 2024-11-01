#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100 //스택의 최대 크기
typedef int element; //데이터의 자료형
element stack[MAX_STACK_SIZE]; //전역 1차원 배열
int top = -1;

//공백 상태 검출 함수
int is_empty(){
    return (top == -1);
}

//포화 상태 검출 함수
int is_full(){
    return (top == (MAX_STACK_SIZE - 1));
}

//삽입 함수
void push(element item){
    if(is_full()){
        return;
    }
    else{
        stack[++top] = item;
    }
}

//삭제 함수
int pop(){
    if(is_empty()){
        return 0;
    }
    else{
        return stack[top--];
    }
}

int main(void){
    push(1);
    push(2);
    push(3);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    return 0;
}

