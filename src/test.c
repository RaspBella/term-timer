#include <string.h>
#include <session.h>
#include <stdio.h>

int main(void)
{
    char *name = strdup("3x3");

    session *new = new_session(name, NULL);

    add_solve(new, new_solve(6.81, strdup(""), strdup("R' D2 B2 D' L' B2 U F' D F2 R D2 L' F2 U2 F2 R' D2 L' D2 F2"), time(NULL)));
    add_solve(new, new_solve(7.72, strdup(""), strdup("B2 F2 U' R2 U L2 D' B2 D F2 R' B' L F2 D F D' R B2 D'"), time(NULL)));

    printf("Session:\n");
    print_session(new);

    reset_session(new);

    add_solve(new, new_solve(7.74, strdup(""), strdup("U2 L2 F' R2 B L2 B2 L2 D2 R2 B' U' R' B' L R2 U' L' R B"), time(NULL)));
    add_solve(new, new_solve(10.32, strdup(""), strdup("B' L' D F' R2 B U2 R' B2 D2 B R2 B2 R2 L2 B L2 D2"), time(NULL)));
    add_solve(new, new_solve(7.74, strdup(""), strdup("B2 U' R2 B2 D' R2 D' B2 F L' U' L' D2 U' B R"), time(NULL)));

    printf("Session:\n");
    print_session(new);

    del_session(new);
}
