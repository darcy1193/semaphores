#Macros?
CC = gcc
CFLAGS = -O -Wall -pthread -pedantic -std=c11   

#Dependencies
main : main.o processes.o 

main.o : processes.h main.h
processes.o : processes.h


#misc targets
clean:
	rm -f *.o core main
run: main
	./main
