#include <stddef.h>
#include <stdio.h>

struct options_s
{
    size_t count;
    const char *alphabet;
    size_t length;
};

typedef struct options_s Options;

void rando(FILE *stream, const Options *options);
