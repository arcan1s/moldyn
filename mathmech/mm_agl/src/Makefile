PROJECT=AGL

CC=gcc
CFLAGS=-c -Wall -fPIC
LDFLAGS=-lm
SOURCES_DIR=src
SOURCES=main.c add_main.c coords.c messages.c print_struct.c read_agl.c select_mol.c set_center.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=mm_agl

$(PROJECT): $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o test*
