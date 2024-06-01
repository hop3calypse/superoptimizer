TARGET = ag2

SRC = src/main.c src/execute.c src/instructions.c

OBJ = $(SRC:.c=.o)

CC = gcc

INCLUDE = -Isrc/

CFLAGS = -Wall -Werror

all: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(CFLAGS) $(INCLUDE)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

debug: CFLAGS += -g
debug: re

.PHONY: all clean fclean re debug
