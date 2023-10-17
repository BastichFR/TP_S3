#include <stdio.h>
#include "fibo.h"

int main(){
	for(unsigned long i = 0; i < 91; i++){
		if(i == 11){
			printf("...\n");
			i+=70;
		}
		printf("fibo(%lu) = %lu\n",i,fibo(i));
	}
	return 0;
}
