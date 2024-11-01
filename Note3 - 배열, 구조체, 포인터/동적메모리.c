#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define SIZE 10

typedef struct {
    char name[10];
    int age;
    double gpa;
} student;

int main(void){
    int* p;
    p = (int*)malloc(SIZE * sizeof(int));
    for (int i = 0; i < SIZE; i++){
        p[i] = i;
        printf("%d ", p[i]);
    }
    free(p);

    student* s;
    s = (student*)malloc(sizeof(student));
    strcpy(s->name, "kim"); //strcpy(*(s).name, "kim");
    s->age = 20;
    s->gpa = 4.2;
    free(s);

    student* s1;
    s1 = (student*)malloc(5 * sizeof(student)); //구조체 배열 s1, 크기는 5
    strcpy(s1[2].name, "park"); //값
    printf("%s\n", s1[2].name);
    strcpy((*(s1+2)).name, "kim"); //주소라서 *으로 접근해 값 접근, 괄호 두개 넣어야함
    printf("%s\n", (*(s1+2)).name);
    strcpy((s1+2)->name, "ye"); //주소라서 ->로 접근
    printf("%s\n", (s1+2)->name);

    free(s1);

    return 0;
}