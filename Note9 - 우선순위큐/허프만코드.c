#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct TreeNode{
    int weight;
    char ch;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct {
    TreeNode* ptree;
    char ch;
    int key;
} element;

typedef struct{
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType* create(){
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h){
    h->heap_size = 0;
}

//현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
//삽입함수
void insert_min_heap(HeapType* h, element item){
    int i;
    i = ++(h->heap_size);

    //트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while((i != 1) && (item.key < h->heap[i/2].key)){ //현재 노드의 키값이 부모 노드 키값보다 작다면
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

//삭제함수
element delete_min_heap(HeapType* h){
    int parent, child;
    element item, temp;
    item = h->heap[1]; //루트 노드;
    temp = h->heap[(h->heap_size)--]; //삭제할 마지막 노드
    parent = 1;
    child = 2;

    while(child <= h->heap_size){
        if(child < h->heap_size && h->heap[child].key > h->heap[child+1].key){ //오른쪽 자식의 값이 더 작다면
            child++;
        }
        if(temp.key < h->heap[child].key){
            break;
        }
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

//이진 트리 생성 함수
TreeNode* make_tree(TreeNode* left, TreeNode* right){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->left = left;
    node->right = right;
    return node;
}

//이진 트리 제거 함수
void destroy_tree(TreeNode* root){
    if(root == NULL){
        return;
    }
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}

int is_leaf(TreeNode* root){
    return !(root->left) && !(root->right); //해당 노드의 왼쪽 노드와 오른쪽 노드가 모두 NULL이면 true 리턴
}

void print_array(int codes[], int n){
    for (int i = 0; i < n; i++){
        printf("%d", codes[i]);
    }
    printf("\n");
}

void print_codes(TreeNode* root, int codes[], int top){
    //1을 저장하고 순환호출한다
    if(root->left){
        codes[top] = 1;
        print_codes(root->left, codes, top + 1);
    }
    //0을 저장하고 순환호출한다
    if(root->right){
        codes[top] = 0;
        print_codes(root->right, codes, top + 1);
    }
    //단말 노드이면 코드를 출력한다
    if(is_leaf(root)){
        printf("%c: ", root->ch);
        print_array(codes, top);
    }
}

//허프만 코드 생성함수
void huffman_tree(int freq[], char ch_list[], int n){
    TreeNode *node, *x;
    HeapType* heap;
    element e, e1, e2;
    int codes[100];
    int top = 0;

    heap = create();
    init(heap);
    for (int i = 0; i < n; i++){
        node = make_tree(NULL, NULL);
        e.ch = node->ch = ch_list[i]; //배열에 있는 문자를 노드에도 넣고 원소에도 넣고
        e.key = node->weight = freq[i]; //빈도수를 노드에도 넣고 원소에도 넣고
        e.ptree = node;
        insert_min_heap(heap, e); //heap은 배열임
    }

    for (int i = 1; i < n; i++){
        //최솟값을 가지는 두개의 노드를 삭제
        e1 = delete_min_heap(heap);
        e2 = delete_min_heap(heap);
        //두개의 노드를 합친다
        x = make_tree(e1.ptree, e2.ptree);
        e.key = e1.key + e2.key;
        e.ptree = x;
        printf("%d+%d->%d \n", e1.key, e2.key, e.key);
        insert_min_heap(heap, e);
    }
    e = delete_min_heap(heap); //최종트리
    print_codes(e.ptree, codes, top);
    destroy_tree(e.ptree);
    free(heap);
}

int main(void){
    char ch_list[] = {'s', 'i', 'n', 't', 'e'};
    int freq[] = {4, 6, 8, 12, 15};
    huffman_tree(freq, ch_list, 5);
    return 0;
}

