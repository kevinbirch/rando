# rando
Generate random strings.

## SYNOPSIS
    rando [-a ALPHA ] [-c COUNT] [-h] LENGTH

## DESCRIPTION

Generates  strings  of  random  characters of user-defined length.  The
single required parameter is a non-zero integer specifying  the  length
of strings to generate.

## OPTIONS
    -a ALPHA, --alphabet=ALPHA
           Customize  the  alphabet  used  to generate random strings.  The
           default is:

           abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789

    -c COUNT, --count=COUNT
           Output the given number of random strings instead of the default
           of 1.

    -h, --help
           Print the help screen and exit.
