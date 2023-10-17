unsigned char digit_count(unsigned long n){
	unsigned char b10 = 0;
	do
	{
		n = n/10;
		b10 += 1;
	}while(n != 0);
	return b10;
}
