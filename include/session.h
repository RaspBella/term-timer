#include <solve.h>
#include <stddef.h>

typedef struct session session;

session *new_session(char*, char*(*)(void));
void del_session(session*);
void add_solve(session*, solve*);
void remove_solve(session*, size_t);
void reset_session(session*);