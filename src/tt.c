#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "data.h"
#include "scramblers.h"

char *filename = NULL;
FILE *fp = NULL;

void cleanup(void)
{
    fp = fopen(filename, "wb");
    write_out_data(fp);
    fclose(fp);
    free_data();
    free(filename);
}

int main(void)
{
    if (atexit(cleanup)) // not 0
    {
        fprintf(stderr, "Failed to register cleanup function\n");
        exit(EXIT_FAILURE);
    }

    #ifdef __linux__
    filename = strdup(getenv("HOME"));
    filename = realloc(filename, strlen(filename)+11);
    filename = strcat(filename, "/.cache/tt");
    filename[strlen(filename)] = 0;
    #endif

    fp = fopen(filename, "rb");
    if (fp) // not NULL
    {
        read_in_data(fp);
        fclose(fp);
    }

    // Do solves and stuff here

    exit(EXIT_SUCCESS);
}