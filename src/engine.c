/*
** EPITECH PROJECT, 2019
** engine.c
** File description:
** engine
*/

#include "unsold.h"

bool process(int a, int b)
{
    float ltab[6][6];
    float stab[10];

    if (a <= 50 || b <= 50) {
        usage();
        return (false);
    }
    tab(a, b, ltab);
    slaw(ltab, stab);
    var(ltab, stab);
    return (true);
}