CC=gcc
CFLAGS=-c -std=c99 -Wall -Wno-format -O2 -DNDEBUG -pedantic
GCCLIBS =
LDFLAGS= -s $(STDLIBS) $(GCCLIBS)
SOURCES=concolors.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=
LIBRARY=libconcolors.a
AR=ar
ARARGS=rcs
RUNLIB=ranlib
RUNLIBARGS=
RM=rm

all: $(SOURCES) $(LIBRARY)

$(LIBRARY): $(OBJECTS)
	$(AR) $(ARARGS) $@ $^

.c.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	$(RM) *.o
	$(RM) $(LIBRARY)
