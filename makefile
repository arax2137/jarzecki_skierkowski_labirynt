CC = gcc

CFLAGS = -Wall -Wextra -std=c99

SRCS = src/main.c src/fhandling.c src/read_path.c src/binary.c src/algorithm.c
HEADERS =src/fhandling.h src/read_path.h src/macro.h src/binary.h src/algorithm.h

OBJS = $(SRCS:.c=.o)

EXEC = program

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(EXEC) $(OBJS)
