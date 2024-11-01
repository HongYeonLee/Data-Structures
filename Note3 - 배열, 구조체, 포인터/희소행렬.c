#include <stdio.h>
#define MAX_TERM 100
typedef struct {
    int row;
    int col;
    int value;
} element;

typedef struct {
    element data[MAX_TERM];
    int rows; //행 개수
    int cols; //열 개수
    int terms; //항 개수
} SparseMatrix;

SparseMatrix matrix_traspose(SparseMatrix a){
    SparseMatrix b;
    int b_index;
    b.rows = a.cols;
    b.cols = a.rows;
    b.terms = a.terms;

    if(a.terms > 0){
        b_index = 0;
        for (int c = 0; c < a.cols; c++){
            for (int i = 0; i < a.terms; i++){
                if(a.data[i].col == c){
                    b.data[b_index].row = a.data[i].col;
                    b.data[b_index].col = a.data[i].row;
                    b.data[b_index].value = a.data[i].value;
                    b_index++;
                }
            }
        }
    }

    return b;
}

void matrix_print(SparseMatrix a){
    printf("=====================\n");
    for (int i = 0; i < a.terms; i++){
        printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].value);
    }
    printf("=====================\n");
}

int main(void){
    SparseMatrix m = {
        {{0, 3, 7}, {1, 0, 9}, {1, 5, 8},
        {3, 0, 6}, {3, 1, 5}, {4, 5, 1},
        {5, 2, 2}},
        6,
        6,
        7
    };

    SparseMatrix result;
    result = matrix_traspose(m);
    matrix_print(result);
    return 0;
}