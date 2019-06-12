all: hello main
	gcc main.o hello.o -o hello

main: main.c
	gcc -c main.c $(CFLAGS)

hello: hello.c
	gcc -c hello.c $(CFLAGS)

clean:
	-rm *.o hello
