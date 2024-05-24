NAME = so_long
BONUS_NAME = so_long_bonus
LIBFT = ./Libft/libft.a
FT_PRINTF = ./ft_printf/ft_printf.a
MLX = ./MLX42
MINILIBX = $(MLX)/build/libmlx42.a
HEAD = ../include/MLX42.h
HEAD2 = ../include/MLX42_int.h

SRCS_1 = \
			main.c \

SRCS_2 = \
			flood_fill.c \
			game.c \
			images.c \
			keyboard.c \
			map.c \
			map_check.c \
			map_check2.c \
			utils_game.c \
			utils.c \
			utils2.c \

SRCS_DIR = sources

OBJS_1 = $(SRCS_1:%.c=$(OBJS_DIR)/%.o)

OBJS_2 = $(SRCS_2:%.c=$(OBJS_DIR)/%.o)

OBJS_DIR = objects

BONUS_SRCS_1 = \
			main_bonus.c \

BONUS_SRCS_2 = \
			flood_fill_bonus.c \
			game_bonus.c \
			images_bonus.c \
			keyboard_bonus.c \
			map_bonus.c \
			map_check_bonus.c \
			map_check2_bonus.c \
			utils_game_bonus.c \
			utils_bonus.c \
			utils2_bonus.c \

BONUS_SRCS_DIR = sources/bonus

BONUS_OBJS_1 = $(BONUS_SRCS_1:%.c=$(BONUS_OBJS_DIR)/%.o)

BONUS_OBJS_2 = $(BONUS_SRCS_2:%.c=$(BONUS_OBJS_DIR)/%.o)

BONUS_OBJS_DIR = objects/bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast
CFLAGS += -g

LFLAGS = -ldl  -L/lib/x86_64-linux-gnu -lglfw -pthread -lm -L./MLX42/build/ -lmlx42

all: mlx42 $(NAME)

mlx42:
	cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4

$(NAME): $(MINILIBX) $(FT_PRINTF) $(LIBFT) $(OBJS_DIR) $(OBJS_1) $(OBJS_2)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJS_1) $(OBJS_2) $(MINILIBX) $(FT_PRINTF) $(LIBFT) -o $(NAME)
	@echo ""
	@echo *******Completed********

$(LIBFT):
	@$(MAKE) -C ./Libft

$(FT_PRINTF):
	@$(MAKE) -C ./ft_printf

$(MINILIBX):
	@${MAKE} -C ./MLX42/build

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) -c -o $@ $^ && printf "Compiling: $(notdir $<)\n"

bonus: mlx42 $(BONUS_NAME)

mlx42:
	cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4

$(BONUS_NAME): $(MINILIBX) $(FT_PRINTF) $(LIBFT) $(BONUS_OBJS_DIR) $(BONUS_OBJS_1) $(BONUS_OBJS_2)
	@$(CC) $(CFLAGS) $(LFLAGS) $(BONUS_OBJS_1) $(BONUS_OBJS_2) $(MINILIBX) $(FT_PRINTF) $(LIBFT) -o $(BONUS_NAME)
	@echo ""
	@echo *******Completed********

$(BONUS_OBJS_DIR):
	@mkdir -p $(BONUS_OBJS_DIR)

$(BONUS_OBJS_DIR)/%.o:$(BONUS_SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) -c -o $@ $^ -I $(HEAD) && printf "Compiling: $(notdir $<)\n"

clean:
	rm -rf $(OBJS_DIR) $(BONUS_OBJS_DIR)
	$(MAKE) clean -C ./Libft
	$(MAKE) clean -C ./ft_printf

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	rm -f ./a.out
	rm -f ./sources/a.out
	rm -f ./so_long
	rm -f ./so_long_bonus
	$(MAKE) fclean -C ./Libft
	$(MAKE) fclean -C ./ft_printf

re: fclean all

.PHONY: all bonus clean fclean re
