#pragma once

#include <stddef.h>
#include <stdio.h>
#include "session.h"

struct data
{
    struct
    {
        unsigned int inspection:2; // off, on, on unless a blind event
        unsigned int timer:1; // normal, typing
        unsigned int multi_phase:3; // 8 possible values should be enough
        unsigned int mbld_stop_at_hour:1; // off, on
        unsigned int show_targets:1; // off, on
    }
    settings;

    size_t session_count;
    struct session *sessions;
    struct session *current_session;
};

extern struct data data;

void read_in_data(FILE*);
void write_out_data(FILE*);