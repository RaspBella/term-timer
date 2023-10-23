SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:src/%.c=obj/%.o)
BINDIR=bin

CC=gcc

CFLAGS=-Wall -Werror -Og -ggdb3 -Iinclude -lncurses -ltinfo

default: ${BINDIR} ${BINDIR}/tt

${BINDIR}:
	mkdir ${BINDIR}

${BINDIR}/tt: ${OBJS}
	${CC} ${CFLAGS} $^ -o $@

obj/%.o: src/%.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${BINDIR}/tt* ${OBJS}

build:
	make CFLAGS="-Wall -O3 -Iinclude -lncurses -ltinfo"