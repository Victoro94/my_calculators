CC = gcc
CFLAGS = -Werror -Wall -Wextra -Wvla -fsanitize=address -pedantic -g 

SRCS = main.c token.c stack.c queue.c
SRCS_TEST = test.c token.c stack.c queue.c

OBJS = $(SRCS:.c=.o)
OBJS_TEST = $(SRCS_TEST:.c=.o)

all : $(OBJS)
	$(CC) $(CFLAGS) -o main $(OBJS)

test : $(OBJS_TEST)
	$(CC) $(CFLAGS) -o test $(OBJS_TEST)

.PHONY: clean

clean:
	$(RM) main test $(OBJS) $(OBJS_TEST)
