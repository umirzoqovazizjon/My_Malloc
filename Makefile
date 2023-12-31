SRC = src
OBJ = obj

CFLAGS += -Wall -Wextra -Werror -fsanitize=address
CC = gcc
TARGET = my_malloc

$(shell mkdir -p obj)

SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS)

$(OBJ)/%.o: $(SRC)/%.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf $(OBJ)/*.o 

fclean: clean
	rm -rf $(TARGET) $(OBJ)

re: 	fclean all

.PHONY: all clean fclean re
