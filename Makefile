output: main.o
	gcc main.o -o blink

main.o: main.c
	gcc -c main.c

clean:
	rm *.o blink