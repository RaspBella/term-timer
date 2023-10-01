#include <stdlib.h>
#include "data.h"

struct data data;

void read_in_data(FILE *fp)
{
    if (fread(&data.settings, sizeof(data.settings), 1, fp) != 1)
    {
        fprintf(stderr, "Error: Couldn't read settings from file\n");
        exit(EXIT_FAILURE);
    }

    if (fread(&data.session_count, sizeof(data.session_count), 1, fp) != 1)
    {
        fprintf(stderr, "Error: Couldn't read session count from file\n");
        exit(EXIT_FAILURE);
    }

    if (data.session_count) // non zero
    {
        data.sessions = malloc(data.session_count * sizeof(struct session));
        for (size_t i = 0; i < data.session_count; i++)
            read_in_session(data.sessions+i, fp);
    }

    size_t temp;
    if (fread(&temp, sizeof(temp), 1, fp) != 1)
    {
        fprintf(stderr, "Error: Couldn't read current session index from file\n");
        exit(EXIT_FAILURE);
    }
    data.current_session = data.sessions+temp;
}

void write_out_data(FILE *fp)
{
    if (fwrite(&data.settings, sizeof(data.settings), 1, fp) != 1)
    {
        fprintf(stderr, "Error: Couldn't write settings to file\n");
        exit(EXIT_FAILURE);
    }

    if (fwrite(&data.session_count, sizeof(data.session_count), 1, fp) != 1)
    {
        fprintf(stderr, "Error: Couldn't write session count to file\n");
        exit(EXIT_FAILURE);
    }
}