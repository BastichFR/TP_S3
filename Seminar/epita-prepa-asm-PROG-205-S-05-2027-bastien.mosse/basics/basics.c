#include <stddef.h>

size_t str_chr(char s[], char c)
{
    size_t id = 0;
    while(s[id] && s[id] != c){
	    id++;
    }
    return id;
}

void str_cat(char s1[], char s2[])
{
	size_t id = 0;
	while(s1[id]) id++;
	for(size_t i = 0; s2[i]; i++){
		s1[id + i] = s2[i];
		s1[id + i + 1] = 0;
	}
}

int str_cmp(char s1[], char s2[])
{
	size_t id;
	for(id = 0; s1[id] && s2[id]; id++){
		if(s1[id] == s2[id]){
			continue;
		} else if(s1[id] < s2[id]){
			return -1;
		} else {
			return 1;
		}
	}
	
	if(!s1[id] && !s2[id]) return 0;
	if(s1[id]) return 1;
	return -1;
}

unsigned int str_toui(char s[])
{
	unsigned int res = 0;
	for(size_t i = 0; s[i]; i++){
		if( '0' <= s[i] && s[i] <= '9'){
			res = res * 10 + (s[i]-48);
		}
	}
	return res;
}

void rm_chr(char c, char s[])
{
	for(size_t id = 0; s[id]; id++){
		if(s[id] == c){
			size_t i = id+1;
			while(s[i] && s[i]==c){ i++; }
			if(s[i]){
				s[id] = s[i];
				s[i] = c;
			} else {
				s[id] = 0;
			}
		}
	}
}
