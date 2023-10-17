unsigned long divisor_sum(unsigned long n){
	unsigned long div_sum = 0;

	for(unsigned long i = 1; i * i <= n; i++){
		if(n%i == 0 && n != 1){
			if( n/i != i && n/i != n){
				div_sum += n/i;
			}
			div_sum += i;
		}
	}

	return div_sum;
}
