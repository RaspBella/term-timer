#include <time.h>

typedef struct solve solve;

solve *new_solve(float, char*, char*, time_t);
void del_solve(solve*);