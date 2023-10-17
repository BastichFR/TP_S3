#include <stdio.h>
#include "isqrt.h"

int main(){
	for(unsigned long int i = 0; i <= 200; i += 8){
		printf("isqrt(%lu) = %lu\n", i, isqrt(i));
	}
	return 0;
}
