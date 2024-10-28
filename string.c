#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
typedef int element;

typedef struct
{
    element data[MAX_STACK_SIZE];
    int top;

} StackType;

// 스택 초기화 함수
void init_stack(StackType *s)
{
    s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType *s)
{
    return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입함수
void push(StackType *s, element item)
{
    if (is_full(s))
    {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else
        s->data[++(s->top)] = item;
}

// 삭제함수
element pop(StackType *s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
        return s->data[(s->top)--];
}

element peek(StackType *s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
        return s->data[s->top];
}

void main()
{
    int letter_count;
    char top;
    char line[100];
    StackType s;
    int cnt = 1; //연속된 문자열의 수

    init_stack(&s);

    printf("문자열: ");
    gets_s(line, 100); // 사용자로부터 문자열 입력 받기
    for (int i = 0; line[i]; i++) { // 소문자로 변환저장
        line[i] = tolower(line[i]);
    }

    //압축 문자열 계산 로직 자성
    char c;
    printf("압축된 문자열: ");
    for (int i = 0; i < strlen(line); i++) {
        c = pop(&s);
        if (c == peek(&s)){
            cnt++;
            pop(&s);
        }
        else{
            printf("%d%c", cnt, c);
            cnt =
        }
    }
}
