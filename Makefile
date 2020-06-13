cc = gcc -g -Wall -lm
LIB_GENL = `pkg-config --cflags --libs libnl-genl-3.0`

all: gluchytelefon.o 1_konsola.o 2_argument.o 3_pipe.o
	$(cc) -o 1_konsola.out gluchytelefon.o 1_konsola.o
	$(cc) -o 2_argument.out gluchytelefon.o 2_argument.o
	$(cc) -o 3_pipe.out gluchytelefon.o 3_pipe.o -lm

gluchytelefon.o: gluchytelefon.c
	$(cc) -c -std=c99 -o $@ $+

1_konsola.o: 1_konsola.c
	$(cc) -c -D _GNU_SOURCE -o $@ $+

2_argument.o: 2_argument.c
	$(cc) -c -D _GNU_SOURCE -o $@ $+

3_pipe.o: 3_pipe.c
	$(cc) -c -D _GNU_SOURCE -o $@ $+

clean:
	rm -f *.out
	rm -f *.o