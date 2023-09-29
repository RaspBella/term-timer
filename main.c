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
    solve *solves;
};

struct data
{
    struct
    {
        int inspection:2; // off, on, on unless a blind event
    }
    settings;
    size_t session_count;
    session *sessions;
}