/*
** EPITECH PROJECT, 2019
** check.c
** File description:
** check
*/

#include <stdlib.h>
#include <stdio.h>

#include "unsold.h"

bool check_num(char *src)
{
    for (int i = 0; src[i];) {
        if (i == 0 && (src[i] == '-' || src[i] == '+'))
            i++;
        else if (src[i] < '0' || src[i] > '9')
            return (false);
        else
            i++;
    }
    return (true);
}

bool check(int ac, char **as, int dat[2])
{
    int i;

    for (i = 1; i < ac; i++) {
        if (i > 2 || !check_num(as[i]))
            return (false);
        dat[i - 1] = atoi(as[i]);
    }
    if (i != 3)
        return (false);
    else
        return (true);
}