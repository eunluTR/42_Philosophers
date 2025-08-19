NAME		:= philo
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

SRC_DIR	:= srcs
INC_DIR	:= includes
OBJ_DIR	:= objs

SRCS		:= \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/simulation/simulation.c \
	$(SRC_DIR)/simulation/utils/diningEating.c \
	$(SRC_DIR)/simulation/utils/diningMonitor.c \
	$(SRC_DIR)/simulation/utils/diningRoutine.c \
	$(SRC_DIR)/simulation/utils/initDining.c \
	$(SRC_DIR)/init/init.c \
	$(SRC_DIR)/init/utils/initTable.c \
	$(SRC_DIR)/init/utils/initPhilos.c \
	$(SRC_DIR)/sync/sync.c \
	$(SRC_DIR)/sync/utils/syncLock.c \
	$(SRC_DIR)/sync/utils/syncGet.c \
	$(SRC_DIR)/sync/utils/syncSet.c \
	$(SRC_DIR)/core/utils/checker.c \
	$(SRC_DIR)/core/utils/display.c \
	$(SRC_DIR)/core/utils/time.c \
	$(SRC_DIR)/core/utils/utils.c \
	$(SRC_DIR)/core/utils/libftUtils.c \
	$(SRC_DIR)/core/utils/free.c

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
