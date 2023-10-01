#include <stdlib.h>
#include <stdio.h>
#include "solve.h"

void read_in_solve(struct solve *solve, FILE *fp)
{
    if (fread(&solve->seconds, sizeof(solve->seconds), 1, fp) != 1)
    {
        fprintf(stderr, "Error: Couldn't read in seconds for solve from file\n");
        exit(EXIT_FAILURE);
    }

    size_t temp;
    if (fread(&temp, sizeof(temp), 1, fp) != 1)
    {
        fprintf(stderr, "Error: Couldn't read in length of comment for solve from file\n");
        exit(EXIT_FAILURE);
    }

    if (temp == 0)
    {
        fprintf(stderr, "Error: Length of comment for solve is invalid\nFile is likely corrupted\n");
        exit(EXIT_FAILURE);
    }

    solve->comment = malloc((temp+1) * sizeof(*solve->comment));
    if (fread(solve->comment, sizeof(*solve->comment), temp, fp) != temp)
    {
        fprintf(stderr, "Error: Couldn't read characters of comment for solve from file\n");
        exit(EXIT_FAILURE);
    }
    solve->comment[temp] = 0;

    if (fread(&temp, sizeof(temp), 1, fp) != 1)
    {
        fprintf(stderr, "Error: Couldn't read in length of scramble for solve from file\n");
        exit(EXIT_FAILURE);
    }

    if (temp == 0)
    {
        fprintf(stderr, "Error: Length of scramble for solve is invalid\nFile is likely corrupted\n");
        exit(EXIT_FAILURE);
    }

    solve->scramble = malloc((temp+1) * sizeof(*solve->scramble));
    if (fread(solve->scramble, sizeof(*solve->scramble), temp, fp) != temp)
    {
        fprintf(stderr, "Error: Couldn't read characters of scramble for solve from file\n");
        exit(EXIT_FAILURE);
    }
    solve->scramble[temp] = 0;

    if (fread(&solve->datetime, sizeof(solve->datetime), 1, fp) != 1)
    {
        fprintf(stderr, "Error: Couldn't read datetime for solve from file\n");
        exit(EXIT_FAILURE);
    }
}