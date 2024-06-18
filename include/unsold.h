/*
** EPITECH PROJECT, 2019
** unsold.h
** File description:
** unsold
*/

#ifndef UNSOLD_H_
	#define UNSOLD_H_

    #include <stdbool.h>

    // check.c

    bool check_num(char *);
    bool check(int, char **, int[2]);

    // engine.c

    bool process(int, int);

    // main.c

    void usage(void);

    // math.c

    void tab(int, int, float[6][6]);
    void slaw(float[6][6], float[10]);
    void var(float[6][6], float[10]);

    // output.c

    void my_put_error(const char *);
    void my_put_str(const char *);


#endif /* !UNSOLD_H_ */