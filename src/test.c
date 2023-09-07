#include <string.h>
#include <session.h>

char *scramble(void)
{
    return NULL;
}

int main(void)
{
    char *name = strdup("3x3");

    session *new = new_session(name, &scramble);

    add_solve(new, new_solve(7.27, strdup("When You See It!"), strdup("U R U' R'"), time(NULL)));

    del_session(new);
}