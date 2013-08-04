PROJECT=TRJ

CC=gcc
CFLAGS=-c -Wall -fPIC
LDFLAGS=-lm
SOURCES_DIR=src
SOURCES=main.c add_main.c atom_types.c messages.c read_gmx.c read_puma.c print_trj.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=mm_trj

$(PROJECT): $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o test*

