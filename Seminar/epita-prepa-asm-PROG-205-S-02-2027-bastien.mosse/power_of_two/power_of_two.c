unsigned long power_of_two(unsigned char n){
	unsigned long t = 2;
	return n == 0 ? 1 : t << (n - (unsigned long)1);
}
