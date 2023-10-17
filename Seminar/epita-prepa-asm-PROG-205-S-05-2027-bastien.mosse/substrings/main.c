#include <stdio.h>
#include <stdlib.h>
#include <err.h>

void exit_help(){
	char help[] = "Usage: str1 str2";
	errx(EXIT_FAILURE, "%s", help);
}


int test_search(const char s1[], const char s2[]){
	int i;
	for(int id = 0; s1[id]; id++){
		if(s1[id] == s2[0]){
			i = 0;	
			while(s1[id + i] && s2[i] && s1[id + i] == s2[i]){
				i++;
			}
			
			if(s1[id + i-1] == s2[i-1] && !s2[i]){
				return id;
			}
		}
	}
	return -1;

}

void search(const char s1[], const char s2[]){
	int awns = test_search(s1, s2);

	if(awns == -1){
		printf("Not Found!\n");
	} else {
		char resp[awns + 1];
		for(int i = 0; i < awns; i++){
			resp[i] = ' ';
		}
		resp[awns] = '^';
		resp[awns + 1] = 0;

		printf("%s\n", s1);
		printf("%s\n", resp);
	}	
}

int main(int argc, char** argv){

	if(argc != 3){ 
		exit_help(); 
	}
	
	char* s1 = argv[1];
	char* s2 = argv[2];

	search(s1, s2);

	return EXIT_SUCCESS;
}
