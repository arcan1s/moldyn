PROJECT=ENVIR

CC=gcc
CFLAGS=-c -Wall -fPIC
LDFLAGS=-lm
SOURCES_DIR=src
SOURCES=main.c add_main.c coords.c envir_search.c messages.c print_struct.c set_center.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=mm_envir

$(PROJECT): $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o test*
