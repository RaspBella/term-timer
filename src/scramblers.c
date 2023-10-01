#include "scramblers.h"

char *s222(size_t seed)
{
    return "2x2x2 scramble";
}

char *s333(size_t seed)
{
    return "3x3x3 scramble";
}

char *(*scramble_generators[])(size_t) = {
    s222,
    s333
};