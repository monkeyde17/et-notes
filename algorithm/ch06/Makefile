CC=g++
CFLAGS=-c -Wall
SOURCES=ch06_heap_sort.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=heap

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
	
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o
	rm $(EXECUTABLE)

run:
	./$(EXECUTABLE)
