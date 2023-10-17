#include <stdio.h>
#include "is_perfect_number.h"

int main(){
	for(unsigned long i = 1; i <= 100000; i++){
		if(is_perfect_number(i)){
			printf("%lu\n", i);
		}
	}
	return 0;
}
