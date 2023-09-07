SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:%.c=%.o)

BIN=tt

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

src/solve.o: src/solve.c include/solve.h
src/session.o: src/session.c include/session.h include/solve.h
src/test.o: src/test.c include/session.h