#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100 //스택의 최대 크기
#define MAZE_SIZE 6 //미로 크기 
typedef struct{
    short r;
    short c;
} element;

element here = {1, 0}, entry = {1, 0};
char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '0', 'x'},
    {'1', '1', '1', '1', '1', '1'}
};

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

element pop(StayckType* s){
    if(is_empty(s)){
        element tmp;
        tmp.r = -1;
        tmp.c = -1;
        return tmp;
    }
    else{
        return s->data[s->top--];
    }
}

//삽입 함수
void push_loc(StayckType* s, int r, int c){
    if (r < 0 || c < 0){
        return;
    }
    if(maze[r][c] != '1' && maze[r][c] != '.'){
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }

}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]){
    printf("\n");
    for (int r = 0; r < MAZE_SIZE; r++){
        for (int c = 0; c < MAZE_SIZE; c++){
            printf("%c", maze[r][c]);
        }
        printf("\n");
    }
}

int main(void){
    int r, c;
    StayckType s;
    inint_stack(&s);
    here = entry;
    while(maze[here.r][here.c] != 'x'){ //현재 위치가 출구가 아니면
        r = here.r;
        c = here.c;
        maze[r][c] = '.'; //현재 위치 방문 표시
        maze_print(maze);
        push_loc(&s, r - 1, c); //위
        push_loc(&s, r + 1, c); //아래
        push_loc(&s, r, c - 1); //왼쪽
        push_loc(&s, r, c + 1); //오른쪽
        if(is_empty(&s)){ //사방이 1또는 .이어서 push가 하나도 안된경우
            printf("실패\n");
            return 0;
        }
        else{
            here = pop(&s);
        }
    }
    printf("성공\n");
    return 0;
}