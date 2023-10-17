#include <stdio.h>
#include "digit_count.h"

int main(){
	unsigned long bit = 0;
	do
	{
		printf("digit_count(%lu) = %u\n", bit, digit_count(bit));
		bit = bit == 0 ? 1 : bit << 1;
	}while (bit > 0);

	return 0;
}
