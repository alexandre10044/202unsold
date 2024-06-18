/*
** EPITECH PROJECT, 2019
** output.c
** File description:
** output
*/

#include <unistd.h>

#include "unsold.h"

void my_put_error(const char *str)
{
	for (int i = 0; str[i]; i++)
	    write(1, &str[i], 1);
}

void my_put_str(const char *str)
{
	for (int i = 0; str[i]; i++)
	    write(1, &str[i], 1);
}