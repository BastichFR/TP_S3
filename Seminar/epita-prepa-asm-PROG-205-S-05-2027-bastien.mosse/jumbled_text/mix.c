#include <stdio.h>

int is_separator(char *a){
	char separator[] = " ,;:!?./%*$=+)@_-('&1234567890\"\r\n";

	for(size_t i = 0; separator[i]; i++){
                if(separator[i] == *a){
                        return 1;
                }
        }
	return 0;
}


void swap(char *a, char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

int can_swap(char *a, char *b){

	if(is_separator(a) || is_separator(b)){
		return 0;
	}

	if( is_separator(a-1) || is_separator(b+1)){
		return 0;
	}

	return 1;
}


void mix(char s[]){
	
	char *a = &s[1];

	for(size_t i = 0; s[i] && s[i+1]; i++){
		if(can_swap(a+i, a+i+1)){
			swap(a+i, a+i+1);
			i++;
		}
	}
}




