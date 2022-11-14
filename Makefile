CC = gcc -g
CFLAGS = -Wall
LDFLAGS = -lm
SOURCES = $(wildcard *.c)
OBJETS = $(SOURCES:.c=.o)
EXEC = main

.PHONY: all
all: $(EXEC)

.PHONY: clean

$(EXEC): $(OBJETS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


%.o : %.c
	$(CC) $(CFLAGS) -c $<


clean:
	rm *.o

doc:

archive:

