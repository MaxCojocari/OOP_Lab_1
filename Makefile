CC				= gcc
CFLAGS			= -std=c11
CFLAGS_DEBUG 	= -std=c11
SOURCES 		= main.c
EXECUTABLE		= main.out

build: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

debug: $(SOURCES)
	$(CC) $(CFLAGS_DEBUG) $(SOURCES) -o $(EXECUTABLE)

clean: $(EXECUTABLE)
	rm *.out