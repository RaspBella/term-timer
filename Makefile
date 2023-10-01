SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:src/%.c=obj/%.o)
BINDIR=bin

CFLAGS=-Wall -Werror -Og -ggdb3 -Iinclude

default: ${BINDIR} ${BINDIR}/tt

${BINDIR}:
	mkdir ${BINDIR}

${BINDIR}/tt: ${OBJS}
	cc ${CFLAGS} $^ -o $@

obj/%.o: src/%.c
	cc ${CFLAGS} -c $< -o $@

clean:
	rm -f ${BINDIR}/tt ${OBJS}

build:
	make CFLAGS="-Wall -O3 -Iinclude"