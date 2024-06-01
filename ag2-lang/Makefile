TARGET = ag2

SRC = main.c execute.c instructions.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror

all: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

debug: CFLAGS += -g
debug: re

.PHONY: all clean fclean re debug
