CC = cc
CFLAGS = -Wall -Wextra -Werror

TARGET = bsq

DEPS = helpers.h

SRCS = main.c helpers.c compliance.c _1Dbuffer.c readmap.c questionarray.c calc.c stdinbuffer.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re