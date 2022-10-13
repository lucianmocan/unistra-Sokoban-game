CC = gcc -g
CFLAGS = -Wall
SOURCES = $(wildcard *.c)
OBJETS = $(SOURCES:.c=.o)
EXEC = main

$(EXEC): $(OBJETS)
	$(CC) $(CFLAGS) -o $@ $^ 


%.o : %.c
	$(CC) $(CFLAGS) -c $<


clean:
	rm *.o
