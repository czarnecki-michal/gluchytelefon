cc = gcc -g -Wall -lm
LIB_GENL = `pkg-config --cflags --libs libnl-genl-3.0`

all: gluchytelefon.o 1_konsola.o 2_argument.o 3_pipe.o 4_jajko.o 5_netlink.o 6_siec.o
	$(cc) -o 1_konsola.out gluchytelefon.o 1_konsola.o
	$(cc) -o 2_argument.out gluchytelefon.o 2_argument.o
	$(cc) -o 3_pipe.out gluchytelefon.o 3_pipe.o -lm
	$(cc) -o 4_jajko.out gluchytelefon.o 4_jajko.o
	$(cc) -o 5_netlink.out gluchytelefon.o 5_netlink.o
	$(cc) -o 6_siec.out gluchytelefon.o 6_siec.o

gluchytelefon.o: gluchytelefon.c
	$(cc) -c -std=c99 -o $@ $+

1_konsola.o: 1_konsola.c
	$(cc) -c -D _GNU_SOURCE -o $@ $+

2_argument.o: 2_argument.c
	$(cc) -c -D _GNU_SOURCE -o $@ $+

3_pipe.o: 3_pipe.c
	$(cc) -c -D _GNU_SOURCE -o $@ $+

4_jajko.o: 4_jajko.c
	$(cc) -c -D _GNU_SOURCE -o $@ $+

5_netlink.o: 5_netlink.c
	$(cc) -c -D _GNU_SOURCE -o $@ $+

6_siec.o: 6_siec.c
	$(cc) -c -D _GNU_SOURCE -o $@ $+

clean:
	rm -f *.out
	rm -f *.o