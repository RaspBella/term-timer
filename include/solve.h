#pragma once

#include <stdio.h>
#include <time.h>

struct solve
{
    float seconds;
    char *comment;
    char *scramble;
    time_t datetime;
};

void read_in_solve(struct solve*, FILE*);
void write_out_solve(const struct solve*, FILE*);
void free_solve(struct solve*);