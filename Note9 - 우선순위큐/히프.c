#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct{
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType* init(){
    HeapType* heap = (HeapType*)malloc(sizeof(HeapType));
    heap->heap_size = 0;
    return heap;
}

//삽입
void insert_max_heap(HeapType* h, element item){
    int i;
    i = ++(h->heap_size); //삽입을 하니 힙의 사이즈가 커짐, 그 커진 인덱스는 가장 마지막 노드를 가리킴

    while((i != 1) && (item.key > h->heap[i/2].key)){ //현재 루트 노드 아니고, 삽입한 노드의 키값이 그 노드의 부모 노드의 키 값보다 크다면
        h->heap[i] = h->heap[i/2]; //현재 노드(자식 노드)에 부모 노드로 대체
        i /= 2; //부모 노드로 이동
    }
    h->heap[i] = item; //새로운 노드를 삽입
}

//삭제
element delete_max_heap(HeapType* h){
    int parent, child;
    element item = h->heap[1]; //루트 노드 저장
    element temp = h->heap[(h->heap_size)--]; //삭제할 가장 마지막 노드를 저장하고 힙의 사이즈를 줄임
    parent = 1;
    child = 2;

    while(child <= h->heap_size){
        //현재 노드의 자식 노드중 더 큰 자식노드를 찾는다
        if((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key){
            child++; //왼쪽 자식보다 오른쪽 자식이 더 크다면 오른쪽 자식으로 대체
        }
        if(temp.key >= h->heap[child].key){ //삭제할 가장 말단 노드의 값이 대체될 값보다 크다면 종료
            break;
        }
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

int main(void){
    element e1 = {10}, e2 ={5}, e3 = {30};
    element e4, e5, e6;
    HeapType* heap;

    heap = init();
    insert_max_heap(heap, e1);
    insert_max_heap(heap, e2);
    insert_max_heap(heap, e3);
    //삭제
    e4 = delete_max_heap(heap);
    printf("< %d > ", e4.key);
    e5 = delete_max_heap(heap);
    printf("< %d > ", e5.key);
    e6 = delete_max_heap(heap);
    printf("< %d > ", e6.key);

    free(heap);
    return 0;

}
