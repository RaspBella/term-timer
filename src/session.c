#include <session.h>
#include <stdlib.h>
#include <solve.h>
#include <string.h>

struct session
{
    char *name;
    char *(*scramble)(void);
    size_t count;
    solve **solves;
};

session *new_session(char *name, char *(*scramble)(void))
{
    session *new = malloc(sizeof(session));

    new->name = name;
    new->scramble = scramble;
    new->count = 0;
    new->solves = NULL;

    return new;
}

void del_session(session *_session)
{
    free(_session->name);

    if (_session->solves != NULL)
        for (size_t i = 0; i < _session->count; i++)
            del_solve(_session->solves[i]);

    free(_session->solves);

    free(_session);
}

void add_solve(session *_session, solve *_solve)
{
    if (_session->count == 0)
        _session->solves = malloc(sizeof(solve*) * ++_session->count);

    else
        _session->solves = realloc(_session->solves, sizeof(solve*) * ++_session->count);

    _session->solves[_session->count-1] = _solve;
}

void remove_solve(session *_session, size_t index)
{
    if (index > _session->count-1) return;

    del_solve(_session->solves[index]);
    
    if (index < _session->count-1)
        memmove(_session->solves+index, _session->solves+_session->count-1, sizeof(solve*));
        
    _session->solves = realloc(_session->solves, sizeof(solve*) * --_session->count);
}

void reset_session(session *_session)
{
    if (_session->solves != NULL)
        for (size_t i = 0; i < _session->count; i++)
            del_solve(_session->solves[i]);
    
    free(_session->solves);

    _session->solves = NULL;
    _session->count = 0;
}

void print_session(session *_session)
{
    if (_session->solves != NULL)
        for (size_t i = 0; i < _session->count; i++)
            print_solve(_session->solves[i]);
}