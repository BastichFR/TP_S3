#include <stddef.h>
#include "split_merge.h"

void split(char s[], char words[][MAX_CHAR])
{
	size_t id_word = 0;
	size_t id_word_lst = 0;
	for(size_t id = 0; s[id]; id++){
		if(s[id] == ' '){
			words[id_word_lst][id_word] = 0;
			id_word_lst++;
			id_word = 0;
			continue;
		} else {
			words[id_word_lst][id_word] = s[id];
			id_word++;
		}
	}
	words[id_word_lst][id_word] = 0;
	words[id_word_lst+1][0] = 0;
}

void merge(char s[], size_t argc, char** argv)
{
	size_t id_s = 0;
	for(size_t icr = 2; icr < argc; icr++){
		size_t id_v = 0;
		while(argv[icr][id_v]){
			s[id_s] = argv[icr][id_v];
			id_s++;
			id_v++;
		}
	}
	s[id_s] = 0;
}
