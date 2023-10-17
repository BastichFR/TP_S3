#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>

void words_free(char** words)
{
    // Frees the strings.
    for (size_t i = 0; words[i]; i++)
        free(words[i]);

    // Frees the string pointers.
    free(words);
}

char* get_word(char* s){
    size_t i = 0;
    while (s[i] && s[i] != ' ')
    {
        i++;
    }

    char* out = (char*)calloc(i+1, sizeof(char));
    for (size_t x = 0; x < i; x++)
        out[x] = s[x];
    out[i] = 0;
    return out;
}

char** split(char* s)
{
    char** words;
    if (strlen(s) == 0)
    {
        words = (char**)calloc(1, sizeof(char*));
        words[0] = NULL;
        return words;
    }

    size_t word_count = 1;
    for (size_t i = 0; s[i]; i++)
    {
        if (s[i] == ' ')
        {
            word_count++;
        }
        
    }
    
    words = (char**)calloc(word_count + 1, sizeof(char*));

    size_t i = 0;
    size_t index = 0;
    while (s[i] && index < word_count)
    {
        words[index++] = get_word(s + i);
        while (s[i] && s[i] != ' ')
        {
            i++;
        }
        i++;
    }
    words[word_count] = NULL;
    return words;
}