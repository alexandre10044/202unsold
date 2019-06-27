/*
** EPITECH PROJECT, 2019
** math.c
** File description:
** math
*/

#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

#include "unsold.h"

static void separator(void)
{
    const char *val = "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";

    printf(val, NULL);
}

void tab(int a, int b, float tab[6][6])
{
    const char *frmt = "\tX=10\tX=20\tX=30\tX=40\tX=50\tY law\n";
    const char *y_s = "Y=%d";
    const char *t_s = "\t%.3f";
    const char *e_s = "\t1\n";
    const char *i_s = "\t%.3f\n";
    int	x;
    float sum[6];

    separator();
    printf(frmt, NULL);
    bzero(sum, sizeof(float) * 6);
    for (int y = 10; y <= 60; y += 10)
    {
        sum[5] = 0;
        printf(y_s, y);
        for (x = 10; x <= 50; x += 10)
        {
            tab[x / 10 - 1][y / 10 - 1] = (y == 60 ? sum[x / 10 - 1] :
            (float)((a - x) * (b - y)) / (float)((5 * a - 150) * (5 * b - 150)));
            sum[x / 10 - 1] += tab[x / 10 - 1][y / 10 - 1];
            printf(t_s, tab[x / 10 - 1][y / 10 - 1]);
            sum[5] += tab[x / 10 - 1][y / 10 - 1];
        }
        if (y == 60)
            printf(e_s, NULL);
        else
            printf(i_s, sum[5]);
        tab[x / 10 - 1][y / 10 - 1] = sum[5];
    }
}


void slaw(float tab[6][6], float stab[10])
{
    const char *frmt = "z\t20\t30\t40\t50\t60\t70\t80\t90\t100\ttotal\n";
    const char *z_s = "p(Z=z)";
    const char *t_s = "\t%.3f";
    const char *i_s = "\t1\n";
    separator();
    bzero(stab, sizeof(float) * 10);
    printf(frmt, NULL);
    printf(z_s, NULL);
    for (int x = 0; x < 5; x++)
    {
        for (int y = 0; y < 5; y++)
        {
            stab[x + y] += tab[x][y];
            stab[9] += tab[x][y];
        }
    }
    for (int x = 0; x < 9; x++)
        printf(t_s, stab[x]);
    printf(i_s, NULL);
}

void var(float tab[6][6], float stab[10])
{
    const char *expect_x = "expected value of X:\t%.1f\n";
    const char *expect_y = "expected value of Y:\t%.1f\n";
    const char *expect_z = "expected value of Z:\t%.1f\n";
    const char *var_x = "variance of X:\t\t%.1f\n";
    const char *var_y = "variance of Y:\t\t%.1f\n";
    const char *var_z = "variance of Z:\t\t%.1f\n";
    float t[6];
    
    bzero(t, sizeof(float) * 6);
    for (int i = 0; i < 5; i++)
    {
        t[0] += (i + 1) * 10 * tab[i][5];
        t[2] += (i + 1) * 10 * tab[5][i];
        t[4] += (i + 2) * 10 * stab[i];
        i++;
    }
    for (int i = 0; i < 5; i++)
    {
        t[1] += ((i + 1) * 10 - t[0]) * ((i + 1) * 10 - t[0]) * tab[i][5];
        t[3] += ((i + 1) * 10 - t[2]) * ((i + 1) * 10 - t[2]) * tab[5][i];
        if (i < 4)
            t[4] += (i + 7) * 10 * stab[i + 5];
    }
    for (int i = 0; i < 9; i++)
        t[5] += ((i + 2) * 10 - t[4]) * ((i + 2) * 10 - t[4]) * stab[i];
    separator();
    printf(expect_x, t[0]);
    printf(var_x, t[1]);
    printf(expect_y, t[2]);
    printf(var_y, t[3]);
    printf(expect_z, t[4]);
    printf(var_z, t[5]);
    separator();
}