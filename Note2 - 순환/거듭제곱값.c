double slow_power(double x, int n){
    int i;
    double result = 1.0;
    for (i = 0; i < n; i++){
        result = result * x;
    }
    return result;
}

double power(int x, int n){
    if (n == 0){
        return 1;
    }
    if (n % 2 == 0){ // 지수가 짝수인 경우, ex) x^8
        return power(x*x, n/2); //return power(x^2, 4), x^8 = (x^2)^4
    }
    else{ //지수가 홀수인 경우, ex) x^7
        return x*power(x*x, (n-1)/2); //return x*power(x^2, 3), x^7 = x*(x^2)3^3
    }
}