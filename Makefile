CC = gcc -g
CFLAGS = -Wall -Wextra
INCLUDE = -Iinstall_dir/include
LDFLAGS = -lm -Wl,-rpath=install_dir/lib -Linstall_dir/lib -lSDL2
SOURCES = $(wildcard *.c)
HEADERS = $(wildcard *.h)
OBJECTS = $(SOURCES:.c=.o)
EXEC = sokoban
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

clean_dependencies:
	rm -rf install_dir

doc:
	doxygen Doxyfile

install_dependencies: 
	cd SDL2 && ./configure --prefix=$(shell pwd)/SDL2/../install_dir && make install -j6

archive:
	tar -cf $(TARNAME).tar.gz $(SOURCES) $(HEADERS) $(LEVELS) Makefile Doxyfile README.md
