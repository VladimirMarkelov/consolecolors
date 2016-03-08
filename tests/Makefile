CC=gcc
CFLAGS=-c -std=c99 -Wall -Wno-format -O2 -DNDEBUG -pedantic
STDLIBS = -lconcolors
GCCLIBS =
LDFLAGS= -s $(STDLIBS) $(GCCLIBS)
SOURCES=test.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=test
LIBRARY=
AR=ar
ARARGS=rcs
RUNLIB=ranlib
RUNLIBARGS=
RM=rm
STRIP=strip --strip-unneeded

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $^ -L. -L.. $(STDLIBS)
	$(STRIP) $(EXECUTABLE)

.c.o:
	$(CC) -I.. $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	$(RM) *.o
	$(RM) $(EXECUTABLE)
