NAME		= philo

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I includes

SRC_DIR		= src
CORE_DIR	= $(SRC_DIR)/core
UTILS_DIR	= $(SRC_DIR)/utils
OBJ_DIR		= obj
OBJ_CORE_DIR	= $(OBJ_DIR)/core
OBJ_UTILS_DIR	= $(OBJ_DIR)/utils

SRC_FILES	= $(SRC_DIR)/main.c \
		  $(CORE_DIR)/philo.c \
		  $(CORE_DIR)/init.c \
		  $(UTILS_DIR)/utils.c \
		  $(UTILS_DIR)/parse.c \
		  $(UTILS_DIR)/log.c

OBJ_FILES	= $(OBJ_DIR)/main.o \
		  $(OBJ_CORE_DIR)/philo.o \
		  $(OBJ_CORE_DIR)/init.o \
		  $(OBJ_UTILS_DIR)/utils.o \
		  $(OBJ_UTILS_DIR)/parse.o \
		  $(OBJ_UTILS_DIR)/log.o

all: $(OBJ_DIRS) $(NAME)

$(OBJ_DIRS):
	@mkdir -p $(OBJ_DIR) $(OBJ_CORE_DIR) $(OBJ_UTILS_DIR)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c | $(OBJ_DIRS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_CORE_DIR)/%.o: $(CORE_DIR)/%.c | $(OBJ_DIRS)
	@mkdir -p $(OBJ_CORE_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_UTILS_DIR)/%.o: $(UTILS_DIR)/%.c | $(OBJ_DIRS)
	@mkdir -p $(OBJ_UTILS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re