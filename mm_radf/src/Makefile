PROJECT=RADF

CC=gcc
CFLAGS=-c -Wall -fPIC
LDFLAGS=-lm
SOURCES_DIR=src
SOURCES=main.c add_main.c coords.c messages.c radf.c radf_proc.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=radf

$(PROJECT): $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o

