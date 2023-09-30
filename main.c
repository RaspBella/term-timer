#include <stdlib.h>
#include <stdio.h>

struct solve
{
    float seconds;
    char *comment;
    char *scramble;
    time_t datetime;
};

struct session
{
    char *name;
    char *(*scramble_generator)(size_t); // takes seed for random and returns scramble as string
    size_t count;
    struct solve *solves;
};

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
};