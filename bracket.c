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
int check_matching(const char *in)
{
    StackType s;
    char ch, open_ch;
    int i, n = strlen(in); // n= 문자열의 길이
    init_stack(&s);        // 스택의 초기화

    int cnt = 0; //괄호의 번호

    for (i = 0; i < n; i++)
    {
        ch = in[i]; // ch = 다음 문자
        switch (ch)
        {
        case '(':
        case '[':
        case '{':
            push(&s, ++cnt);
            printf("%d ", cnt);
            break;
        case ')':
        case ']':
        case '}':
            if (is_empty(&s))
                return 0;
            else
            {
                printf("%d", pop(&s));
                break;
            }
        }
    }
    if (!is_empty(&s))
        return 0; // 스택에 남아있으면 오류
    return 1;
}

int main(void)
{
    char line[100];
    printf("수식: ");
    gets_s(line, 100);
    printf("괄호수: ");
    check_matching(line);
    return 0;
}