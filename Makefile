CC=gcc

CFLAGS=-std=c17 -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion \
         -Wshadow -Wpointer-arith -Wcast-qual -Wwrite-strings \
         -Wstrict-prototypes -Wmissing-prototypes -Wformat=2 \
         -Wundef -Wdouble-promotion -Wfloat-equal \
         -Wnull-dereference -Wswitch-enum

TARGET=calculator.exe
TESTS=tests

OBJS = compute.o io.o main.o

.PHONY: tests clean

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) -lm 

$(TESTS): $(TARGET)
	./$(TARGET) < tests/basic.in > tests/basic.actual
	diff tests/basic.expected tests/basic.actual
	./$(TARGET) < tests/errors.in > tests/errors.actual
	diff tests/errors.expected tests/errors.actual

clean:
	rm -f $(OBJS) $(TARGET)
