TARGET=main

SOURCES=$(wildcard *.cpp)

OBJS=$(SOURCES:.cpp=.o)

CC=g++
CFLAGS= -pedantic -g 
CXXFLAGS=$(CFLAGS)
LDFLAGS= -g
LDLIBS = -lgtest -lgtest_main -pthread

.PHONY: clean run gdb

$(TARGET): $(OBJS)

include .depends

.depends:
	$(CC) -MM  $(SOURCES) > .depends

clean:
	rm -f $(OBJS) $(TARGET) .depends

run: $(TARGET)
	./$(TARGET)
	
valgrind:
	valgrind chmod a+x./$(SOURCES)

gdb: $(TARGET)
	gdb -q ./$(TARGET)
	
