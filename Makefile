CC = gcc -g
CFLAGS = -Wall -Wextra
INCLUDE = -Iinstall_dir/include
LDFLAGS = -lm -Wl,-rpath=install_dir/lib -Linstall_dir/lib -lSDL2
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
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDE) $(LDFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< 

clean:
	rm -rf $(OBJECTS) $(EXEC) $(DOCS) $(TARNAME).tar.gz

doc:
	doxygen Doxyfile

archive:
	tar -cf $(TARNAME).tar.gz $(SOURCES) $(HEADERS) $(LEVELS) Makefile Doxyfile README.md
