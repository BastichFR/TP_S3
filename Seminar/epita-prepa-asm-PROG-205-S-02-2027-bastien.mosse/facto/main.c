#include <stdio.h>
#include "facto.h"

int main(){
	for(unsigned long i = 0; i < 21; i++){
		printf("facto(%lu) = %lu\n", i, facto(i));
	}
	return 0;
}
