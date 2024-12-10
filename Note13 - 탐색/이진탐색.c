int search_binary(int key, int low, int high, int list[]){
    int middle;
    if(low < high){ //아직 숫자들이 남아있으면
        middle = (low + high) / 2;
        if(list[middle] == key){ //탐색 성공
            return middle;
        }
        else if (key > list[middle]){
            return search_binary(key, middle + 1, high, list); //오른쪽 부분 리스트 탐색
        }
        else{
            return search_binary(key, low, middle - 1, list); //왼쪽 부분 리스트 탐색
        }
    }
    return -1;
}

//반복 버전
int search_binary2(int key, int low, int high, int list[]){
    int middle;
    while(low < high){
        middle = (low + high) / 2;
        if(list[middle] == key){
            return middle;
        }
        else if (key < list[middle]){
            high = middle - 1;
        }
        else{
            low = middle + 1;
        }
    }
    return -1;
}
