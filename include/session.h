#pragma once

#include <stddef.h>
#include <stdio.h>
#include "solve.h"
#include "scramblers.h"

struct session
{
    char *name;
    char *(*scramble_generator)(size_t); // takes seed for random and returns scramble as string
    size_t count;
    struct solve *solves;
};

void read_in_session(struct session*, FILE*);
void write_out_session(const struct session*, FILE*);