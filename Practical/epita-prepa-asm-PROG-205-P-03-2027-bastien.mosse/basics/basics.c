#define _GNU_SOURCE
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

unsigned long* array_fibo(size_t n)
{
    unsigned long* fibo;
    fibo = (unsigned long*)calloc(n, sizeof(unsigned long));
    if (fibo == NULL) {
        exit(1);
        return NULL;
    }

    for (size_t i = 0; i < n; i++)
    {
        if(i < 2){
            *(fibo + i) = i;
        } else {
            *(fibo + i) = *(fibo + i - 1) + *(fibo + i - 2);
        }
    }

    return fibo;    
}

char* str_toupper(const char* s)
{
    char* dest = (char*)calloc(strlen(s)+1, sizeof(char));

    for (size_t i = 0; s[i]; i++) {
        dest[i] = toupper((char)s[i]);
    }
    
    dest[strlen(s)] = '\0';
    return dest;
}

unsigned char* array_pal_1(unsigned char* a, size_t len)
{
    a = (unsigned char*)realloc(a, len*2);
    for (size_t i = 0; i < len; i++)
        a[2*len - i - 1] = a[i];

    return a;
}

void array_pal_2(unsigned char** a, size_t len)
{
    unsigned char* out = *a;
    out = (unsigned char*)realloc(out, len*2);
    for (size_t i = 0; i < len; i++)
        out[2*len - i - 1] = out[i];

    *a = out;
}

size_t array_min(unsigned char* a, size_t len, unsigned char threshold, unsigned char** result)
{
    size_t len2 = 0;
    unsigned char which[len];

    for (size_t i = 0; i < len; i++)
    {
        if (a[i] < threshold)
        {
            which[i] = 1;
            len2++;
        }
        else
        {
            which[i] = 0;
        }
    }

    if (len2 == 0)
    {
        *result = NULL;
        return 0;
    }

    unsigned char* out = *result;
    out = (unsigned char*)realloc(NULL, len2);

    size_t x = 0, y = 0;
    while (x < len && y < len2)
    {
        if (which[x] == 1)
        {
            out[y++] = a[x];
        }
        x++;
    }

    *result = out;
    return len2;
}

void str_checksum(char** s)
{
    char* string = *s;
    int checksum = 0;
    size_t len = strlen(string);

    for (size_t i = 0; i < len; i++) {
        checksum += (int)string[i];
    }

    char* result = NULL;
    asprintf(&result, "%s (%X)", string, checksum);

    free(*s);
    *s = result;

}