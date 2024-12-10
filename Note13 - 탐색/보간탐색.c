int interpol_search(int key, int n, int list[]){
    int low, high, j;
    low = 0;
    high = n - 1;
    while(list[high] >= key && list[low] < key){
        j = ((float)((key - list[low]) * (high - low)) / (list[high] - list[low]) + low);
        if(key > list[j]){
            low = j + 1;
        }
        else if (key < list[j]){
            high = j - 1;
        }
        else{
            low = j;
        }
    }
    if(list[low] == key){
        return low;
    }
    return -1;
}