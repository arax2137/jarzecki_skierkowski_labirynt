CC = gcc
CFLAGS = -Wall

SRCS = main.c algorithm.c fhandling.c read_path.c
OBJS = $(SRCS:.c=.o)

all: app

app: $(OBJS)
    @$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
    @$(CC) $(CFLAGS) -c $< -o $@

clean:
    @rm -f app $(OBJS)
