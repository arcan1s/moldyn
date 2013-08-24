PROJECT=STATGEN

CC=gcc
CFLAGS=-c -Wall -fPIC
LDFLAGS=-lm
SOURCES_DIR=src
SOURCES=main.c add_main.c coords.c graph.c messages.c stat_print.c stat_select.c stat_sort.c summary_stat.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=mm_statgen

$(PROJECT): $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o test*
