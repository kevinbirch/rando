#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <getopt.h>

#include "rando.h"

static const char * const DEFAULT_ALPHABET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

static struct option long_options[] = 
{
    {"alphabet", required_argument, NULL, 'a'},
    {"count", required_argument, NULL, 'c'},
    {"help", no_argument, NULL, 'h'},
    {NULL, 0, NULL, 0}
};

static void usage(void)
{
    printf("Generate random strings.\n"
           "\n"
           "Usage:\n"
           "  rando [options] LENGTH\n"
           "  rando -h | --help\n"
           "\n"
           "Options:\n"
           "  -h --help                  Show this screen.\n"
           "  -a ALPHA --alphabet=ALPHA  Use ALPHA as the output alphabet. [default: lower, upper, digit]\n"
           "  -c COUNT --count=COUNT     Print COUNT random strings. [default: 1]\n");
}

static unsigned long must_atoi(const char *restrict str, const char *restrict name)
{
    errno = 0;
    unsigned long result = strtoul(str, NULL, 10);
    if(errno == ERANGE)
    {
        fprintf(stderr, "rando: %s is too large.\n", name);
        exit(EXIT_FAILURE);
    }
    if(errno != 0)
    {
        perror("rando");
        exit(EXIT_FAILURE);
    }
    if(result == 0)
    {
        fprintf(stderr, "rando: %s must be an integer.\n", name);
        exit(EXIT_FAILURE);
    }

    return result;
}

int main(int argc, char **argv)
{
    Options options = {.count=1, .alphabet=DEFAULT_ALPHABET};
    int ch;
    while((ch = getopt_long(argc, argv, "a:c:h", long_options, NULL)) != -1)
    {
        switch(ch)
        {
            case 'a':
            {
                size_t alpha_len = strlen(optarg);
                if(alpha_len == 0)
                {
                    fprintf(stderr, "rando: ALPHA must be a non-zero length string.\n");
                    exit(EXIT_FAILURE);
                }
                for(size_t i = 0; i < alpha_len; i++)
                {
                    if(isprint(optarg[i]) == 0)
                    {
                        fprintf(stderr, "rando: ALPHA characters must be printable ASCII.\n");
                        exit(EXIT_FAILURE);
                    }
                }
                options.alphabet = optarg;
                break;
            }
            case 'c':
            {
                options.count = must_atoi(optarg, "COUNT");
                break;
            }
            case 'h':
            default:
                usage();
                exit(EXIT_SUCCESS);
        }
    }
    argc -= optind;
    argv += optind;

    if(argc <= 0)
    {
        fprintf(stderr, "rando: LENGTH must be provided.");
        exit(EXIT_FAILURE);
    }
    options.length = must_atoi(*argv, "LENGTH");

    rando(stdout, &options);

    exit(EXIT_SUCCESS);
}
