#include <stdlib.h>
#include <stdio.h>

#include "data.h"
#include "scramblers.h"

int main(void)
{
    FILE *test = fopen("test.bin", "wb");
    if (test) write_out_data(test);

    printf("test: %s\n", scramble_generators[0](0));

    exit(EXIT_SUCCESS);
}