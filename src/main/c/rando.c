#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rando.h"

static void fill_string(char *str, size_t length, const char *alphabet)
{
    size_t alpha_len = strlen(alphabet);
    for(size_t i = 0; i < length; i++)
    {
        int j = 1+(int)(((double)alpha_len)*random()/(RAND_MAX+1.0));
        str[i] = alphabet[j - 1];
    }
}

void rando(FILE *stream, const Options *options)
{
    char *str = malloc(options->length + 1);
    if(str == NULL)
    {
        perror("rando");
        return;
    }
    srandomdev();
    str[options->length] = '\n';
    for(size_t i = 0; i < options->count; i++)
    {
        fill_string(str, options->length, options->alphabet);
        fwrite(str, options->length + 1, 1, stream);
    }

    free(str);
}
