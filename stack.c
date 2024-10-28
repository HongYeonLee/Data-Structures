#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
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

int main(void)
{
    StackType s;
    int size;
    int array[MAX_STACK_SIZE];
    int num;

    init_stack(&s);

    printf("정수 배열의 크기: ");
    scanf("%d", &size);

    printf("정수를 입력하시오: ");
    // 정수 입력 받는 코드 작성(반복문)
    // 스택에 순서대로 push
    for (int i = 0; i < size; i++){
        scanf("%d", &num);
        push(&s, num);
    }

    printf("반전된 정수 배열: ");
    // 스택 내용 pop해서 출력 (반복문)
    for (int i = 0; i < size; i++){
        printf("%d ", pop(&s));
    }

    printf("\n");
    return 0;
}
