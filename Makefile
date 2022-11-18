CC = gcc -g
CFLAGS = -Wall -Wextra
LDFLAGS = -lm
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
DOCS = html
EXEC = main

.PHONY: all
all: $(EXEC)

.PHONY: clean

.PHONY: doc

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJECTS) $(EXEC) $(DOCS)

doc:
	doxygen Doxyfile

archive:

