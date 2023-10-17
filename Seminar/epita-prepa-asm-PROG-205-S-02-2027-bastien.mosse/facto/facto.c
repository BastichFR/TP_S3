unsigned long facto(unsigned long n){
    return n == 0 ? 1 : n * facto(n-1);
}