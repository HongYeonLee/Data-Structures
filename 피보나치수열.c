//반복으로 구현
int fib_iter(int n){
    int pp = 0;
    int p = 1;
    int result = 0;

    for (int i = 2; i < n; i++){
        result = pp + p;
        pp = p;
        p = result;
    }
    return result;
}

//순환으로 구현

int fib(int n){
    if (n == 0){
        return 0;
    }

    if (n == 1){
        return 1;
    }
    return fib(n-1) + fib(n-2);
}