NAME		:= philo
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

SRC_DIR	:= srcs
INC_DIR	:= includes
OBJ_DIR	:= objs

SRCS		:= \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/simulation/diningEating.c \
	$(SRC_DIR)/simulation/diningMonitor.c \
	$(SRC_DIR)/simulation/diningRoutine.c \
	$(SRC_DIR)/simulation/initDining.c \
	$(SRC_DIR)/init/initTable.c \
	$(SRC_DIR)/init/initPhilos.c \
	$(SRC_DIR)/init/initLocks.c \
	$(SRC_DIR)/init/initShared.c \
	$(SRC_DIR)/sync/syncLock.c \
	$(SRC_DIR)/sync/syncGet.c \
	$(SRC_DIR)/sync/syncSet.c \
	$(SRC_DIR)/utils/checker.c \
	$(SRC_DIR)/utils/display.c \
	$(SRC_DIR)/utils/time.c \
	$(SRC_DIR)/utils/libftString.c \
	$(SRC_DIR)/utils/libftChar.c \
	$(SRC_DIR)/utils/free.c

OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCLUDES	:= -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/philo.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	find $(SRC_DIR) -type f -name '*.o' -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
