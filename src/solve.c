#include <solve.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

struct solve
{
    float seconds;
    char *comment;
    char *scramble;
    time_t datetime;
};

solve *new_solve(float seconds, char *comment, char *scramble, time_t datetime)
{
    solve *new = malloc(sizeof(solve));

    new->seconds = seconds;
    new->comment = comment;
    new->scramble = scramble;
    new->datetime = datetime;

    return new;
}

void del_solve(solve *_solve)
{
    free(_solve->comment);
    free(_solve->scramble);
    free(_solve);
}

void print_solve(solve* _solve)
{
    printf("%s%.2f %s %s\n", ctime(&_solve->datetime), _solve->seconds, _solve->comment, _solve->scramble);
}