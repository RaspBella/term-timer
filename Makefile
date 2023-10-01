SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:src/%.c=obj/%.o)

BIN=bin/tt

CFLAGS=-Wall -Werror -Og -ggdb3 -Iinclude

default: ${BIN}

${BIN}: ${OBJS}
	cc ${CFLAGS} $^ -o $@

obj/%.o: src/%.c
	cc ${CFLAGS} -c $< -o $@

clean:
	rm -f ${BIN} ${OBJS}

build:
	make CFLAGS="-Wall -O3 -Iinclude"