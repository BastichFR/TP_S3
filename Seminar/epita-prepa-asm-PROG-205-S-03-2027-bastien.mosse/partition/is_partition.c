#include <stddef.h>

long is_partition(unsigned char a[], size_t len, unsigned char pivot)
{
	size_t is_p;
	for(size_t id_p = 0; id_p < len; id_p++){
		if(a[id_p] == pivot){
			is_p = 1;
			for(size_t id = 0; id < id_p; id++){
				a[id] > a[id_p] ? is_p = 0 : is_p;
			}
			for(size_t id = id_p+1; id < len; id++){
				a[id] < a[id_p] ? is_p = 0 : is_p;
			}
			if(is_p){ return id_p; }
		}
	}
	return -1;
}
