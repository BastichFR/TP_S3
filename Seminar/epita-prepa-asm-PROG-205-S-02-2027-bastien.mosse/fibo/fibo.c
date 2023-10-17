unsigned long fibo(unsigned long n){
	switch (n)
	{
	case 0 :
		return 0;
	case 1 :
	case 2 :
		return 1;
	default:
		return fibo(n-1) + fibo(n-2);
    }
}
