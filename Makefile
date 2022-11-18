CC = gcc -g
CFLAGS = -Wall -Wextra
LDFLAGS = -lm
SOURCES = $(wildcard *.c)
HEADERS = $(wildcard *.h)
OBJECTS = $(SOURCES:.c=.o)
EXEC = main
DOCS = html
LEVELS = $(wildcard *.txt)
TARNAME = MOCAN_Lucian

.PHONY: all
all: $(EXEC)

.PHONY: clean

.PHONY: doc

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJECTS) $(EXEC) $(DOCS) $(TARNAME).tar.gz

doc:
	doxygen Doxyfile

archive:
	tar -cf $(TARNAME).tar.gz $(SOURCES) $(HEADERS) $(LEVELS) Doxyfile README.md
