PROJECT=STATGEN

CC=gcc
CFLAGS=-c -Wall -fPIC
LDFLAGS=-lm
SOURCES=main.c coords.c int2str.c messages.c stat_print.c stat_select.c stat_sort.c summary_stat.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=statgen

$(PROJECT): $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o

