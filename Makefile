CC=gcc
CFLAGS = -std=c17 -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion \
         -Wshadow -Wpointer-arith -Wcast-qual -Wwrite-strings \
         -Wstrict-prototypes -Wmissing-prototypes -Wformat=2 \
         -Wundef -Wdouble-promotion -Wfloat-equal \
         -Wnull-dereference -Wswitch-enum

TARGET=calculator

OBJS = compute.o io.o main.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)