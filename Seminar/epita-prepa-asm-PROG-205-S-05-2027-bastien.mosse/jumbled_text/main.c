#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mix.h"



int main(int argc, char** argv){

	char* str;	
	
	if(argc != 2){
		
		str = (char*)malloc(sizeof(char) * strlen("This is the default text.") + 1);
		strcpy(str, "This is the default text.");
	} else {
		str = (char*)malloc(sizeof(char) * strlen(argv[1]) + 1);
		strcpy(str, argv[1]);
	}

	printf("%s\n", str);

	mix(str);

	printf("%s\n", str);

	free(str);

	return EXIT_SUCCESS;
}

