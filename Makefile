NAME		= philo

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I includes

SRC_DIR		= src
UTILS_DIR	= utils

SRC_FILES	=	$(SRC_DIR)/main.c \
				$(UTILS_DIR)/utils.c \

OBJ_FILES	= $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re