#include <stdlib.h>
#include <string.h>

int is_occ(const char* s, const char* occ){
    size_t i;
    for (i = 0; s[i] && occ[i]; i++)
    {
        if (s[i] != occ[i])
        {
            return 0;
        }
    }

    if(occ[i] == 0){
        return 1;
    }

    return 0;
}


int nb_occ(const char *s, const char* occ){
    int count = 0;
    
    for (size_t i = 0; s[i]; i++)
    {
        if (s[i] == occ[0])
        {
            count += is_occ(s + i, occ);
        }
    }
    
    return count;
}


char* replace(const char* s, const char* from, const char* to)
{
    int count = nb_occ(s, from); 
    
    int new_len = strlen(s) - count * strlen(from) + count * strlen(to) + 1;
    char* out = (char*)calloc(new_len, sizeof(char));

    int index = 0;
    for (size_t i = 0; s[i] && index < new_len-1; i++)
    {
        if (is_occ(s + i, from) == 1)
        {
            i += strlen(from) - 1;
            for (size_t x = 0; x < strlen(to); x++)
            {
                out[index] = to[x];
                index++;
            }
        }
        else
        {
            out[index] = s[i];
            index++;
        }
    }
    return out;
}