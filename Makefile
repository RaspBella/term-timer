SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:%.c=%.o)

BIN=bin/tt

CFLAGS=-Wall -Werror -Og -ggdb3 -Iinclude

default: ${BIN}

${BIN}: ${OBJS}
	cc ${CFLAGS} $^ -o $@

%.o: %.c
	cc ${CFLAGS} -c $< -o $@

clean:
	rm -f ${BIN} ${OBJS}

build:
	make CFLAGS="-Wall -O3 -Iinclude"