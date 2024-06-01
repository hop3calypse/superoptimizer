TARGET = ag2

SRC = main.c

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

.PHONY: all clean fclean re
