CFLAGS = -c -Wall -Werror -fpic -I/usr/include/lua5.3

default: test.so

test.so: test.o
	gcc -shared -o $@ $<

test.o: test.c
	gcc $(CFLAGS) -o $@ $<
