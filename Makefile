stack:smain.o stack_ll.o
	gcc -Wall -g -o stack stack_ll.o smain.o

stack_ll.o: stack_ll.c stack_ll.h
	gcc -Wall -g -c stack_ll.c

smain.o: smain.c stack_ll.c stack_ll.h
	gcc -Wall -g -c smain.c

clean:
	rm -f *.o stack
