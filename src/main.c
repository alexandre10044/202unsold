/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include <string.h>
#include <stdio.h>

#include "unsold.h"

static void help(const char *name)
{
    const char *val = "USAGE\n"
                    "\t   %s a b\n"
                    "DESCRIPTION\n"
                    "\t   a\tconstant computed from the past results\n"
                    "\t   b\tconstant computed from the past results\n";
    printf(val, name);
}

void usage(void)
{
    const char *val = "Bad usage.";

    my_put_error(val);
}

int main(int ac, char **as)
{
    const int success = 0;
    const int fail = 84;
    int dat[2];

    if (ac == 2 && strcmp(as[1], "-h") == 0) {
        help(as[0]);
        return (success);
    }
    if (!(check(ac, as, dat))) {
        usage();
        return (fail);
    }
    if (process(dat[0], dat[1]))
        return (success);
    else
        return (fail);
}