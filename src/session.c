#include <stdlib.h>
#include "session.h"

void read_in_session(struct session *session, FILE *fp)
{
    size_t temp;
    if (fread(&temp, sizeof(temp), 1, fp) != 1)
    {
        fprintf(stderr, "Error: Couldn't read length of name for session from file\n");
        exit(EXIT_FAILURE);
    }

    if (temp == 0)
    {
        fprintf(stderr, "Error: Length of name for session is invalid\nFile is likely corrupted\n");
        exit(EXIT_FAILURE);
    }

    session->name = malloc((temp+1) * sizeof(*session->name));
    if (fread(session->name, sizeof(*session->name), temp, fp) != temp)
    {
        fprintf(stderr, "Error: Couldn't read characters of name for session from file\n");
        exit(EXIT_FAILURE);
    }
    session->name[temp] = 0;

    if (fread(&temp, sizeof(temp), 1, fp) != 1)
    {
        fprintf(stderr, "Error: Couldn't read scramble generator id for session from file\n");
        exit(EXIT_FAILURE);
    }
    session->scramble_generator = scramble_generators[temp];

    if (fread(&session->count, sizeof(session->count), 1, fp) != 1)
    {
        fprintf(stderr, "Error: Couldn't read solve count for session from file\n");
        exit(EXIT_FAILURE);
    }

    if (session->count) // non zero
    {
        session->solves = malloc(session->count * sizeof(struct solve));
        for (size_t i = 0; i < session->count; i++)
            read_in_solve(session->solves+i, fp);
    }
}