int seq_search(int key, int low, int high, int list[]){
    int i;
    for (i = low; i <= high; i++){
        if(list[i]==key){
            return i;
        }
    }
    return -1;
}

int seq_search(int key, int low, int high, int list[]){
    int i;
    list[high + 1] = key;
    for (i = low; list[i] != key; i++){
        ;
    }
    if(i == (high + 1)){
        return -1;
    }
    else{
        return i;
    }
}